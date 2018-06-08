#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 Pos;
out vec3 Normal;

uniform mat4 model;
layout (std140) uniform Matrices
{
	mat4 projection;
	mat4 view;
};

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
    TexCoords = aTexCoords;
	Normal = mat3(transpose(inverse(model))) * aNormal;
	Pos = vec3(model * vec4(aPos, 1.0));
}