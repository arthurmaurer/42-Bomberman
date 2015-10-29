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

in vec3		position;
in vec3		normal;
in vec2		uv;

out	data
{
	vec2	uv;
	vec3	normal;
	vec3	position;
	vec3	eyePosition;
	vec3	toLight[LIGHT_COUNT];
}			outdata;

uniform PointLight	light[LIGHT_COUNT];
uniform mat4		modelViewMatrix;
uniform mat4		mvp;

void	main()
{
	vec4	worldPosition = vec4(position, 1.0) * modelViewMatrix;

	outdata.eyePosition = -worldPosition.xyz;
	outdata.position = position;
	outdata.normal = normal;
	outdata.uv = uv;

	for (uint i = 0; i < LIGHT_COUNT; i++)
	{
		vec4	lightWorldPosition = vec4(light[i].position, 1.0) * modelViewMatrix;
		outdata.toLight[i] = normalize(lightWorldPosition - worldPosition).xyz;
	}

	gl_Position = vec4(position, 1.0) * mvp;
}
