#version 330 core
out vec4 FragColor;

in VS_OUT {
	vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
	vec4 FragPosLightSpace;
	mat3 TBN;
} fs_in;

uniform sampler2D texture1;
uniform sampler2D shadowMap;
uniform vec3 viewPos;
uniform vec3 lightPosition;
uniform vec3 lightColor;

vec3 BlinnPhong(vec3 normal, vec3 fragPos, vec3 lightPos, vec3 lightColor, vec4 fragPosLightSpace);
float ShadowCalculation(vec4 fragPosLightSpace, vec3 normal, vec3 lightDir);

void main()
{    
    vec4 color = texture(texture1, fs_in.TexCoords);
	vec3 ambient = 0.03 * color.rgb;
	vec3 lighting = ambient + BlinnPhong(normalize(fs_in.Normal), fs_in.FragPos, lightPosition.rgb, lightColor.rgb, fs_in.FragPosLightSpace);
	color *= vec4(lighting, 1.0);
	FragColor = color;
}

vec3 BlinnPhong(vec3 normal, vec3 fragPos, vec3 lightPos, vec3 lightColor, vec4 fragPosLightSpace)
{
    // diffuse
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * lightColor;
    // specular
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);
    vec3 specular = spec * lightColor;
    // simple attenuation
    //float max_distance = 1.5;
    //float distance = length(lightPos - fragPos);
    //float attenuation = 1.0 / (distance);

	//Calculate shadow
	float shadow = ShadowCalculation(fragPosLightSpace, normal, lightDir);
	vec3 lighting = (1.0 - shadow) * (diffuse + specular);
	//vec3 lighting = (diffuse + specular);
    
    //diffuse *= attenuation;
    //specular *= attenuation;
    
    return lighting;
}

float ShadowCalculation(vec4 fragPosLightSpace, vec3 normal, vec3 lightDir)
{
	vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
	projCoords = projCoords * 0.5 + 0.5;
	
	float closestDepth = texture(shadowMap, projCoords.xy).r;
	float currentDepth = projCoords.z;

	//float bias = max(0.02 * (1.0 - dot(normal, lightDir)), 0.0002); //When we don't have face culling
	float bias = 0.0002;
	//float shadow = currentDepth - bias > closestDepth ? 1.0 : 0.0;
	float shadow = 0.0;
	vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
	for(int x = -1; x <= 1; ++x)
	{
		for(int y = -1; y <= 1; ++y)
		{
			float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
			shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
		}
	}
	shadow /= 9.0;
	if(projCoords.z > 1.0)
		shadow = 0.0;
	return shadow;
}
