#version 330 core
layout (triangles) in;
layout (line_strip, max_vertices = 6) out;

in VS_OUT 
{
	vec3 pos;
	vec2 texCoords;
	vec3 normal;
} gs_in[];

layout (std140) uniform Matrices
{
	mat4 projection;
	mat4 view;
};
uniform mat4 model;
uniform float time;

const float MAGNITUDE = 0.4;

vec3 GetNormal();
void GenerateLine(int index);

void main() 
{
	GenerateLine(0);
	GenerateLine(1);
	GenerateLine(2);
}

vec3 GetNormal()
{
	vec3 a = vec3(gs_in[0].pos) - vec3(gs_in[1].pos);
	vec3 b = vec3(gs_in[2].pos) - vec3(gs_in[1].pos);
	return normalize(cross(b, a));
}

void GenerateLine(int index)
{
	gl_Position = projection * view * model * vec4(gs_in[index].pos, 1.0);
	EmitVertex();
	gl_Position = projection * view * model * (vec4(gs_in[index].pos, 1.0) + vec4(gs_in[index].normal, 0.0) * MAGNITUDE);
	EmitVertex();
	EndPrimitive();
}