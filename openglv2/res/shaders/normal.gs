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
	vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
	vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
	return normalize(cross(b, a));
}

void GenerateLine(int index)
{
	gl_Position = projection * view * gl_in[index].gl_Position;
	EmitVertex();
	gl_Position = projection * view * (gl_in[index].gl_Position + vec4(GetNormal(), 0.0) * MAGNITUDE);
	EmitVertex();
	EndPrimitive();
}