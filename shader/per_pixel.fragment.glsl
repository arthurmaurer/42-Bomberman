#version 400 core

struct PointLight
{
	vec3	position;
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
	vec3	toLight;
}			input;

out vec4	finalColor;

uniform PointLight	light;
uniform mat3		normalMatrix;
uniform sampler2D	diffuseSampler;

vec3	getLightIntensity()
{
	vec3	tNorm;
	vec3	eyeDirection;
	vec3	reflection;
	vec3	ambientIntensity;
	vec3	diffuseIntensity;
	vec3	specularIntensity = vec3(0, 0, 0);
	float	brightness;

	tNorm = normalize(input.normal * normalMatrix);
	// eyeDirection = normalize(-input.eyePosition);
	eyeDirection = vec3(0, 0, 1.0);
	reflection = reflect(-input.toLight, tNorm);

	brightness = max(dot(input.toLight, tNorm), 0);
	diffuseIntensity = light.diffuse * brightness;
	brightness = dot(reflection, eyeDirection);

	if (brightness >= 0)
		specularIntensity = light.specular * pow(brightness, 10.f);

	ambientIntensity = light.ambient * 0.1;

	return ambientIntensity + diffuseIntensity + specularIntensity;
}

void	main()
{
	vec4	diffuse;
	vec3	lightIntensity;

	lightIntensity = getLightIntensity();
	diffuse = texture(diffuseSampler, input.uv);
	finalColor = vec4(lightIntensity, 1.0) * diffuse;
}
