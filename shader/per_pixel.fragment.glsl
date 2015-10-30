#version 400 core

#define LIGHT_COUNT	2

struct	PointLight
{
	vec3	position;
	vec3	ambient;
	vec3	diffuse;
	vec3	specular;
	vec2	attenuation;
};

struct	LightColor
{
	vec3	ambient;
	vec3	diffuse;
	vec3	specular;
};

in	data
{
	vec2	uv;
	vec3	normal;
	vec3	toLight[LIGHT_COUNT];
}			indata;

uniform PointLight	lights[LIGHT_COUNT];
uniform mat3		normalMatrix;
uniform mat4		viewMatrix;
uniform sampler2D	diffuseSampler;

out vec4	finalColor;

vec3	mergeLightColor(const LightColor color)
{
	return (color.ambient + color.diffuse + color.specular);
}

void	applyAttenuation(const PointLight light, const vec3 toLight, LightColor lightColor)
{
	float	distance;
	float	attenuation;

	distance = length(toLight);
	attenuation = 1.0 + light.attenuation.x * distance + light.attenuation.y * distance * distance;

	lightColor.ambient /= attenuation;
	lightColor.diffuse /= attenuation;
	lightColor.specular /= attenuation;
}

vec3	getSpecularColor(const PointLight light, const vec3 toLight)
{
	vec3			reflection;
	float			brightness;
	vec3			color = vec3(0.0, 0.0, 0.0);
	vec3			eyeDirection = vec3(0.0, 0.0, 1.0);

	reflection = reflect(-toLight, indata.normal);
	brightness = dot(reflection, eyeDirection);

	if (brightness >= 0.0)
		color = light.specular * pow(brightness, 15.0);

	return color;
}

vec3	getDiffuseColor(const PointLight light, const vec3 toLight)
{
	float	brightness = max(dot(toLight, indata.normal), 0.0);

	return light.diffuse * brightness;
}

vec3	getAmbientColor(const PointLight light)
{
	return light.ambient * 0.1;
}

vec3	getPointLightColor(const PointLight light, const vec3 toLight)
{
	LightColor		lightColor;
	vec3			lightDirection = normalize(toLight);

	lightColor.diffuse = getDiffuseColor(light, lightDirection);
	lightColor.specular = getSpecularColor(light, lightDirection);
	lightColor.ambient = getAmbientColor(light);

	applyAttenuation(light, toLight, lightColor);

	return mergeLightColor(lightColor);
}

void	main()
{
	vec4	diffuse;
	vec3	lightIntensity = vec3(0, 0, 0);

	for (uint i = 0; i < LIGHT_COUNT; i++)
		lightIntensity += getPointLightColor(lights[i], indata.toLight[i]);

	diffuse = texture2D(diffuseSampler, indata.uv);
	finalColor = vec4(lightIntensity, 1.0) * diffuse;
}
