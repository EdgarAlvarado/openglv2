#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Pos;
in vec3 Normal;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;
uniform sampler2D texture_height1;
uniform samplerCube skybox;
uniform vec3 cameraPos;
uniform mat4 model;

void main()
{
	vec4 finalColor;
	vec4 diffuse = texture(texture_diffuse1, TexCoords);
	vec3 normal = texture(texture_normal1, TexCoords).rgb;
	vec4 reflFactor = texture(texture_height1, TexCoords);

	vec3 I = normalize(Pos - cameraPos);
	vec3 R = reflect(I, normalize(Normal));
	vec4 reflectColor = vec4(texture(skybox, R).rgb, 1.0);

	//finalColor = (reflFactor.r * reflectColor) + ((1.0 - reflFactor.r) * diffuse);
	finalColor = ((reflFactor.r * reflectColor) + (1.0 - reflFactor.r)) + diffuse;
	//finalColor = (1.0 - diffuse) + ( reflectColor * reflFactor);

    FragColor = vec4(reflectColor.rgb, 1.0);
	//FragColor = vec4(TexCoords, 0.0, 1.0);
	//FragColor = Pos;
}

