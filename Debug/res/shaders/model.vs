#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out VS_OUT
{
	vec3 pos;
	vec2 texCoords;
	vec3 normal;
} vs_out;

uniform mat4 model;
layout (std140) uniform Matrices
{
	mat4 projection;
	mat4 view;
};

void main()
{
	gl_Position = model * vec4(aPos, 1.0);
    vs_out.texCoords = aTexCoords;
	vs_out.normal = aNormal;
	vs_out.pos = aPos;
}