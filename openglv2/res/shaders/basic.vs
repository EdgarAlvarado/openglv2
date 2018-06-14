#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aTangent;

out vec2 TexCoords;
out VS_OUT {
	vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
	mat3 TBN;
} vs_out;

uniform mat4 model;
layout (std140) uniform Matrices
{
	mat4 projection;
	mat4 view;
};

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	vs_out.FragPos = vec3(model * vec4(aPos, 1.0));
	vs_out.Normal = aNormal;
    vs_out.TexCoords = aTexCoords;
	vec3 T = normalize(vec3(model * vec4(aTangent, 0.0)));
	vec3 N = normalize(vec3(model * vec4(aNormal, 0.0)));
	vec3 B = cross(N, T);
	vs_out.TBN = mat3(T, B, N);
}