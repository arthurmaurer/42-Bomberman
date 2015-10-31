#version 400 core

#define LIGHT_COUNT			3

#define DISABLED_LIGHT		0
#define POINT_LIGHT			1
#define DIRECTIONAL_LIGHT	2
#define SPOT_LIGHT			3

struct	Light
{
	int		type;
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
	vec3	toLight[LIGHT_COUNT];
}			outdata;

uniform Light		lights[LIGHT_COUNT];
uniform mat3		normalMatrix;
uniform mat4		modelViewMatrix;
uniform mat4		viewMatrix;
uniform mat4		mvp;

void	setToLights()
{
	vec4	worldPosition = vec4(position, 1.0) * modelViewMatrix;

	for (uint i = 0; i < LIGHT_COUNT; i++)
	{
		vec4	lightPosition = vec4(lights[i].position, 1.0) * viewMatrix;
		outdata.toLight[i] = lightPosition.xyz - worldPosition.xyz;
	}
}

void	main()
{
	gl_Position = vec4(position, 1.0) * mvp;

	outdata.normal = normalize(normal * normalMatrix);
	outdata.uv = uv;

	setToLights();
}
