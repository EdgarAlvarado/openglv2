#version 330 core
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in VS_OUT 
{
	vec3 pos;
	vec2 texCoords;
	vec3 normal;
} gs_in[];

out vec3 Pos;
out vec2 TexCoords;
out vec3 Normal;

layout (std140) uniform Matrices
{
	mat4 projection;
	mat4 view;
};
uniform mat4 model;
uniform float time;
uniform bool exploding;

vec4 explode(vec4 position, vec3 normal);
vec3 GetNormal();

void main() {
	vec3 normal = GetNormal();

	gl_Position = projection * view * explode(gl_in[0].gl_Position, normal);
	TexCoords = gs_in[0].texCoords;
	Normal = mat3(transpose(inverse(model))) * gs_in[0].normal;
	Pos = vec3(model * vec4(gs_in[0].pos, 1.0));
	EmitVertex();
	gl_Position = projection * view * explode(gl_in[1].gl_Position, normal);
	TexCoords = gs_in[1].texCoords;
	Normal = mat3(transpose(inverse(model))) * gs_in[1].normal;
	Pos = vec3(model * vec4(gs_in[1].pos, 1.0));
	EmitVertex();
	gl_Position = projection * view * explode(gl_in[2].gl_Position, normal);
	TexCoords = gs_in[2].texCoords;
	Normal = mat3(transpose(inverse(model))) * gs_in[2].normal;
	Pos = vec3(model * vec4(gs_in[2].pos, 1.0));
	EmitVertex();
	EndPrimitive();
}

vec4 explode(vec4 position, vec3 normal)
{
	float magnitude = 2.0;
	vec3 direction = normal * ((sin(time) + 1.0) / 2.0) * magnitude;
	if (exploding)
		return position + vec4(direction, 0.0);
	else
		return position;
}

vec3 GetNormal()
{
	vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
	vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
	return normalize(cross(b, a));
}