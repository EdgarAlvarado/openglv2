#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D screenTexture;
uniform bool inverse;
uniform bool grayScale;
uniform bool kernel;

const float offset = 1.0 / 300.0;

void main()
{    
	vec4 texColor = texture(screenTexture, TexCoords);
	if(kernel)
	{
		vec2 offsets[9] = vec2[](
			vec2(-offset,  offset), // top-left
			vec2( 0.0f,    offset), // top-center
			vec2( offset,  offset), // top-right
			vec2(-offset,  0.0f),   // center-left
			vec2( 0.0f,    0.0f),   // center-center
			vec2( offset,  0.0f),   // center-right
			vec2(-offset, -offset), // bottom-left
			vec2( 0.0f,   -offset), // bottom-center
			vec2( offset, -offset)  // bottom-right    
		);
		/*float kernelA[9] = float[](
			1,  1, 1,
			1, -8, 1,
			1,  1, 1
		);*/
		float kernelA[9] = float[](
			1.0 / 16, 2.0 / 16, 1.0 / 16,
			2.0 / 16, 4.0 / 16, 2.0 / 16,
			1.0 / 16, 2.0 / 16, 1.0 / 16  
		);
    
		vec3 sampleTex[9];
		for(int i = 0; i < 9; i++)
		{
			sampleTex[i] = vec3(texture(screenTexture, TexCoords.st + offsets[i]));
		}
		vec3 col = vec3(0.0);
		for(int i = 0; i < 9; i++)
			col += sampleTex[i] * kernelA[i];
		texColor = vec4(col, 1.0);
	}
	if(inverse)
		texColor = vec4(vec3(1.0 - texColor), 1.0);
	if(grayScale)
	{
		float average = 0.2126 * texColor.r + 0.7152 * texColor.g + 0.0722 * texColor.b;
		texColor = vec4(average, average, average, 1.0);
	}
    FragColor = texColor;
}