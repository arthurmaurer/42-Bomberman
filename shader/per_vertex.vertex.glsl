#version 400 core

in vec3		position;
in vec3		normal;
in vec2		uv;

out	data
{
	vec2	uv;
	vec3	lightIntensity;
}			output;

struct PointLight
{
	vec3	position;
	vec3	ambient;
	vec3	diffuse;
	vec3	specular;
};

uniform PointLight	light;
uniform mat4		modelViewMatrix;
uniform mat3		normalMatrix;
uniform mat4		mvp;

vec3	getLightIntensity()
{
	vec3	tNorm;
	vec3	eyeCoords;
	vec3	eyeDirection;
	vec3	toLight;
	vec3	reflection;
	vec3	ambientIntensity;
	vec3	diffuseIntensity;
	vec3	specularIntensity = vec3(0, 0, 0);
	float	brightness;

	tNorm = normalize(normal * normalMatrix);
	eyeCoords = (vec4(position, 1.0) * modelViewMatrix).xyz;
	// eyeDirection = normalize(-eyeCoords);
	eyeDirection = vec3(0, 0, 1.0);
	toLight = normalize(light.position - eyeCoords);
	reflection = reflect(-toLight, tNorm);

	brightness = max(dot(toLight, tNorm), 0.2);
	diffuseIntensity = light.diffuse * brightness;
	brightness = dot(reflection, eyeDirection);

	if (brightness >= 0)
		specularIntensity = light.specular * pow(brightness, 10.f);
	
	ambientIntensity = light.ambient * 0.1;

	return ambientIntensity + diffuseIntensity + specularIntensity;
}

void	main()
{
	output.lightIntensity = getLightIntensity();
	gl_Position = vec4(position, 1.0) * mvp;
	output.uv = uv;
}
