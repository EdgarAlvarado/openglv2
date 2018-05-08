#version 330 core
out vec4 FragColor;

in vec3 ourPos;
in vec2 TexCoord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
uniform float blendFactor;

void main()
{
    //FragColor = texture(ourTexture1, TexCoord) * vec4(ourColor, 1.0f);
	FragColor = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), blendFactor);
}