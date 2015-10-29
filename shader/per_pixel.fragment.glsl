#version 400 core

#define LIGHT_COUNT	3

struct	PointLight
{
	vec3	position;
	vec3	ambient;
	vec3	diffuse;
	vec3	specular;
	vec2	attenuation;
};

struct	LightIntensity
{
	vec3	ambient;
	vec3	diffuse;
	vec3	specular;
};

in	data
{
	vec2	uv;
	vec3	normal;
	vec3	position;
	vec3	eyePosition;
	vec3	toLight[LIGHT_COUNT];
}			indata;

out vec4	finalColor;

uniform PointLight	light[LIGHT_COUNT];
uniform mat3		normalMatrix;
uniform sampler2D	diffuseSampler;

vec3	applyAttenuation(uint lightID, LightIntensity intensity)
{
	float	distance;
	float	attenuation;

	distance = length(indata.toLight[lightID]);
	attenuation = 1.0 + light[lightID].attenuation.x * distance + light[lightID].attenuation.y * distance * distance;

	return intensity.ambient + intensity.diffuse + intensity.specular;

	return (intensity.ambient / attenuation +
		intensity.diffuse / attenuation +
		intensity.specular / attenuation);
}

vec3	getLightIntensity(uint lightID)
{
	vec3			tNorm;
	vec3			eyeDirection;
	vec3			reflection;
	float			brightness;
	LightIntensity	intensity;

	intensity.ambient = vec3(0, 0, 0);
	intensity.diffuse = vec3(0, 0, 0);
	intensity.specular = vec3(0, 0, 0);

	tNorm = normalize(indata.normal * normalMatrix);
	//eyeDirection = normalize(indata.eyePosition);
	eyeDirection = vec3(0, 0, 1.0);

	brightness = max(dot(indata.toLight[lightID], tNorm), 0);
	intensity.diffuse = light[lightID].diffuse * brightness;

	reflection = reflect(-indata.toLight[lightID], tNorm);
	brightness = dot(reflection, eyeDirection);

	if (brightness >= 0)
		intensity.specular = light[lightID].specular * pow(brightness, 15.f);

	intensity.ambient = light[lightID].ambient * 0.1;

	return applyAttenuation(lightID, intensity);
}

void	main()
{
	vec4	diffuse;
	vec3	lightIntensity = vec3(0, 0, 0);

	for (uint i = 0; i < LIGHT_COUNT; i++)
		lightIntensity += getLightIntensity(i);

	diffuse = texture(diffuseSampler, indata.uv);
	finalColor = vec4(lightIntensity, 1.0) * diffuse;
}
