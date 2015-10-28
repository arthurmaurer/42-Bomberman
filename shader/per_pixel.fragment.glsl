#version 400 core

#define LIGHT_COUNT	3

struct PointLight
{
	vec3	position;
	vec3	ambient;
	vec3	diffuse;
	vec3	specular;
	vec2	attenuation;
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

vec3	getLightIntensity(uint lightID)
{
	vec3	tNorm;
	vec3	eyeDirection;
	vec3	reflection;
	vec3	ambientIntensity;
	vec3	diffuseIntensity;
	vec3	specularIntensity = vec3(0, 0, 0);
	float	distance;
	float	attenuation;
	float	brightness;

	distance = length(indata.toLight[lightID]);
	tNorm = normalize(indata.normal * normalMatrix);
	// eyeDirection = normalize(-indata.eyePosition);
	eyeDirection = vec3(0, 0, 1.0);
	reflection = reflect(-indata.toLight[lightID], tNorm);

	brightness = max(dot(indata.toLight[lightID], tNorm), 0);
	diffuseIntensity = light[lightID].diffuse * brightness;
	brightness = dot(reflection, eyeDirection);

	attenuation = 1.0 +
		light[lightID].attenuation.x * distance +
		light[lightID].attenuation.y * distance * distance;

	if (brightness >= 0)
		specularIntensity = light[lightID].specular * pow(brightness, 10.f);

	ambientIntensity = light[lightID].ambient * 0.1;

	return ambientIntensity / attenuation + diffuseIntensity / attenuation + specularIntensity / attenuation;
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
