#version 400 core

struct PointLight
{
	vec3	position;
	vec3	ambient;
	vec3	diffuse;
	vec3	specular;
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
	vec3	toLight;
}			output;

uniform PointLight	light;
uniform mat4		modelViewMatrix;
uniform mat4		mvp;

void	main()
{
	output.eyePosition = (vec4(position, 1.0) * modelViewMatrix).xyz;
	output.toLight = normalize(light.position - output.eyePosition);
	output.position = position;
	output.normal = normal;
	
	gl_Position = vec4(position, 1.0) * mvp;
	output.uv = uv;
}
