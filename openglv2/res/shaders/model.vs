#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out VS_OUT
{
	vec2 texCoords;
	vec4 normal;
} vs_out;
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
	gl_Position = model * vec4(aPos, 1.0);
    vs_out.texCoords = aTexCoords;
	Normal = mat3(transpose(inverse(model))) * aNormal;
	vs_out.normal = normalize(projection * view * mat4(mat3(transpose(inverse(model)))) * vec4(aNormal, 0.0));
	Pos = vec3(model * vec4(aPos, 1.0));
}