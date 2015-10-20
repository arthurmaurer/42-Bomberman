#version 400 core

in data
{
	vec2	uv;
	vec3	lightIntensity;
}			input;

out vec4	finalColor;

uniform sampler2D	diffuseSampler;

void	main()
{
	vec4	diffuse;

	diffuse = texture(diffuseSampler, input.uv);

	finalColor = vec4(input.lightIntensity, 1.0) * diffuse;
}
