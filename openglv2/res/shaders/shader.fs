#version 330 core

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};
struct Light {
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

struct SpotLight {
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};
out vec4 FragColor;

uniform Material material;
uniform Light light;
uniform SpotLight flashLight;
uniform vec3 viewPos;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

vec3 calculateSpotLight()
{
	vec3 result;
	vec3 lightDir = normalize(flashLight.position - FragPos);
	float theta = dot(lightDir, normalize(-flashLight.direction));
	float epsilon = flashLight.cutOff - flashLight.outerCutOff;
	float intensity = clamp((theta - flashLight.outerCutOff) / epsilon, 0.0, 1.0);

	float distance = length(flashLight.position - FragPos);
	float attenuation = 1.0 / (flashLight.constant + flashLight.linear * distance + flashLight.quadratic * (distance * distance));

	vec3 ambient = flashLight.ambient * vec3(texture(material.diffuse, TexCoords));

	vec3 norm = normalize(Normal);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = flashLight.diffuse * (diff * vec3(texture(material.diffuse, TexCoords)));

	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = flashLight.specular * (spec * vec3(texture(material.specular, TexCoords)));

	diffuse *= intensity * attenuation;
	specular *= intensity * attenuation;

	result = (ambient + diffuse + specular);
	return result;
}

void main()
{
	float distance = length(light.position - FragPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * (diff * vec3(texture(material.diffuse, TexCoords)));

	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * (spec * vec3(texture(material.specular, TexCoords)));

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	vec3 flashLightResult = calculateSpotLight();

	vec3 result = (ambient + diffuse + specular);
    FragColor = vec4(result + flashLightResult, 1.0f);
}