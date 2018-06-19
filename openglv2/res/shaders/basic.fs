#version 330 core
out vec4 FragColor;

in VS_OUT {
	vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
	mat3 TBN;
} fs_in;

uniform sampler2D texture1;
uniform samplerCube shadowMap;
uniform vec3 viewPos;
uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform float far_plane;

vec3 sampleOffsetDirections[20] = vec3[]
(
   vec3( 1,  1,  1), vec3( 1, -1,  1), vec3(-1, -1,  1), vec3(-1,  1,  1), 
   vec3( 1,  1, -1), vec3( 1, -1, -1), vec3(-1, -1, -1), vec3(-1,  1, -1),
   vec3( 1,  1,  0), vec3( 1, -1,  0), vec3(-1, -1,  0), vec3(-1,  1,  0),
   vec3( 1,  0,  1), vec3(-1,  0,  1), vec3( 1,  0, -1), vec3(-1,  0, -1),
   vec3( 0,  1,  1), vec3( 0, -1,  1), vec3( 0, -1, -1), vec3( 0,  1, -1)
); 

vec3 BlinnPhong(vec3 normal, vec3 fragPos, vec3 lightPos, vec3 lightColor);
float ShadowCalculation(vec3 fragPos);

void main()
{    
    vec4 color = texture(texture1, fs_in.TexCoords);
	vec3 ambient = 0.03 * color.rgb;
	vec3 lighting = ambient + BlinnPhong(normalize(fs_in.Normal), fs_in.FragPos, lightPosition.rgb, lightColor.rgb);
	color *= vec4(lighting, 1.0);
	FragColor = color;
}

vec3 BlinnPhong(vec3 normal, vec3 fragPos, vec3 lightPos, vec3 lightColor)
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
	float shadow = ShadowCalculation(fragPos);
	vec3 lighting = (1.0 - shadow) * (diffuse + specular);
	//vec3 lighting = (diffuse + specular);
    
    //diffuse *= attenuation;
    //specular *= attenuation;
    
    return lighting;
}

float ShadowCalculation(vec3 fragPos)
{
	vec3 fragToLight = fragPos - lightPosition;

	float currentDepth = length(fragToLight);

	float bias = 0.05;
	float shadow = 0.0;
	int samples = 20;
	float viewDistance = length(viewPos - fragPos);
	float diskRadius = (1.0 + (viewDistance / far_plane)) / 25.0;
	for(int i = 0; i < samples; ++i)
	{
		float closestDepth = texture(shadowMap, fragToLight + sampleOffsetDirections[i] * diskRadius).r;
		closestDepth *= far_plane;
		shadow += currentDepth - bias > closestDepth ? 1.0: 0.0;;
	}
	shadow /= float(samples);
	//FragColor = vec4(vec3(closestDepth / far_plane), 1.0);

	return shadow;
}
