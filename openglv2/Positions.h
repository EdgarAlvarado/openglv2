#ifndef POSITIONS_H
#define POSITIONS_H
#include <glm/glm.hpp>

float cubeVertices[] = {
	// Back face
	-0.5f, -0.5f, -0.5f,	0.0f,  0.0f, -1.0f,		0.0f, 0.0f,  // Bottom-left
	 0.5f,  0.5f, -0.5f,	0.0f,  0.0f, -1.0f,		1.0f, 1.0f, // top-right
	 0.5f, -0.5f, -0.5f,	0.0f,  0.0f, -1.0f,		1.0f, 0.0f, // bottom-right         
	 0.5f,  0.5f, -0.5f,	0.0f,  0.0f, -1.0f,		1.0f, 1.0f, // top-right
	-0.5f, -0.5f, -0.5f,	0.0f,  0.0f, -1.0f,		0.0f, 0.0f,  // bottom-left
	-0.5f,  0.5f, -0.5f,	0.0f,  0.0f, -1.0f,		0.0f, 1.0f,  // top-left
	// Front face
	-0.5f, -0.5f,  0.5f,	0.0f,  0.0f, 1.0f,		0.0f, 0.0f,  // bottom-left
	 0.5f, -0.5f,  0.5f,	0.0f,  0.0f, 1.0f,		1.0f, 0.0f, // bottom-right
	 0.5f,  0.5f,  0.5f,	0.0f,  0.0f, 1.0f,		1.0f, 1.0f, // top-right
	 0.5f,  0.5f,  0.5f,	0.0f,  0.0f, 1.0f,		1.0f, 1.0f, // top-right
	-0.5f,  0.5f,  0.5f,	0.0f,  0.0f, 1.0f,		0.0f, 1.0f,  // top-left
	-0.5f, -0.5f,  0.5f,	0.0f,  0.0f, 1.0f,		0.0f, 0.0f,  // bottom-left
	// Left face
	-0.5f,  0.5f,  0.5f,	-1.0f,  0.0f,  0.0f,	1.0f, 0.0f, // top-right
	-0.5f,  0.5f, -0.5f,	-1.0f,  0.0f,  0.0f,	1.0f, 1.0f, // top-left
	-0.5f, -0.5f, -0.5f,	-1.0f,  0.0f,  0.0f,	0.0f, 1.0f, // bottom-left
	-0.5f, -0.5f, -0.5f,	-1.0f,  0.0f,  0.0f,	0.0f, 1.0f, // bottom-left
	-0.5f, -0.5f,  0.5f,	-1.0f,  0.0f,  0.0f,	0.0f, 0.0f, // bottom-right
	-0.5f,  0.5f,  0.5f,	-1.0f,  0.0f,  0.0f,	1.0f, 0.0f, // top-right
	// Right face
	0.5f,  0.5f,  0.5f,		1.0f,  0.0f,  0.0f,		1.0f, 0.0f, // top-left
	0.5f, -0.5f, -0.5f,		1.0f,  0.0f,  0.0f,		0.0f, 1.0f, // bottom-right
	0.5f,  0.5f, -0.5f,		1.0f,  0.0f,  0.0f,		1.0f, 1.0f, // top-right         
	0.5f, -0.5f, -0.5f,		1.0f,  0.0f,  0.0f,		0.0f, 1.0f, // bottom-right
	0.5f,  0.5f,  0.5f,		1.0f,  0.0f,  0.0f,		1.0f, 0.0f, // top-left
	0.5f, -0.5f,  0.5f,		1.0f,  0.0f,  0.0f,		0.0f, 0.0f, // bottom-left     
	// Bottom face
	-0.5f, -0.5f, -0.5f,	0.0f, -1.0f,  0.0f,		0.0f, 1.0f,  // top-right
	 0.5f, -0.5f, -0.5f,	0.0f, -1.0f,  0.0f,		1.0f, 1.0f, // top-left
	 0.5f, -0.5f,  0.5f,	0.0f, -1.0f,  0.0f,		1.0f, 0.0f, // bottom-left
	 0.5f, -0.5f,  0.5f,	0.0f, -1.0f,  0.0f,		1.0f, 0.0f, // bottom-left
	-0.5f, -0.5f,  0.5f,	0.0f, -1.0f,  0.0f,		0.0f, 0.0f,  // bottom-right
	-0.5f, -0.5f, -0.5f,	0.0f, -1.0f,  0.0f,		0.0f, 1.0f,  // top-right
	// Top face
	-0.5f,  0.5f, -0.5f,	0.0f,  1.0f,  0.0f,		0.0f, 1.0f, // top-left
	 0.5f,  0.5f,  0.5f,	0.0f,  1.0f,  0.0f,		1.0f, 0.0f,// bottom-right
	 0.5f,  0.5f, -0.5f,	0.0f,  1.0f,  0.0f,		1.0f, 1.0f,// top-right     
	 0.5f,  0.5f,  0.5f,	0.0f,  1.0f,  0.0f,		1.0f, 0.0f,// bottom-right
	-0.5f,  0.5f, -0.5f,	0.0f,  1.0f,  0.0f,		0.0f, 1.0f, // top-left
	-0.5f,  0.5f,  0.5f,	0.0f,  1.0f,  0.0f,		0.0f, 0.0f// bottom-left
};
vector<glm::vec3> cubeTangents;
float skyboxVertices[] = {
	// positions          
	-1.0f,  1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,

	-1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,

	1.0f, -1.0f, -1.0f,
	1.0f, -1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f,  1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,

	-1.0f, -1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,

	-1.0f,  1.0f, -1.0f,
	1.0f,  1.0f, -1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f, -1.0f,

	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	1.0f, -1.0f,  1.0f
};
float planeVertices[] = {
	// positions			//Normals		// texture Coords (note we set these higher than 1 (together with GL_REPEAT as texture wrapping mode). this will cause the floor texture to repeat)
	-5.0f, -0.5f, -5.0f,	0.0, 1.0, 0.0,	0.0f, 2.0f,
	-5.0f, -0.5f,  5.0f,	0.0, 1.0, 0.0,	0.0f, 0.0f,
	5.0f, -0.5f,  5.0f,		0.0, 1.0, 0.0,	2.0f, 0.0f,

	5.0f, -0.5f, -5.0f,		0.0, 1.0, 0.0,	2.0f, 2.0f,
	-5.0f, -0.5f, -5.0f,	0.0, 1.0, 0.0,	0.0f, 2.0f,
	5.0f, -0.5f,  5.0f,		0.0, 1.0, 0.0,	2.0f, 0.0f
};
vector<glm::vec3> planeTangents;
float transparentVertices[] = {
	// positions			//Normals		// texture Coords (swapped y coordinates because texture is flipped upside down)
	0.0f,  0.5f,  0.0f,		0.0, 0.0, 1.0, 0.0f,  0.0f,
	0.0f, -0.5f,  0.0f,		0.0, 0.0, 1.0, 0.0f,  1.0f,
	1.0f, -0.5f,  0.0f,		0.0, 0.0, 1.0, 1.0f,  1.0f,

	0.0f,  0.5f,  0.0f,		0.0, 0.0, 1.0, 0.0f,  0.0f,
	1.0f, -0.5f,  0.0f,		0.0, 0.0, 1.0, 1.0f,  1.0f,
	1.0f,  0.5f,  0.0f,		0.0, 0.0, 1.0, 1.0f,  0.0f
};
vector<glm::vec3> transparentTangents;
float quadVertices[] = {
	// positions   // texCoords
	-1.0f,  1.0f,  0.0f, 1.0f,
	-1.0f, -1.0f,  0.0f, 0.0f,
	1.0f, -1.0f,  1.0f, 0.0f,

	-1.0f,  1.0f,  0.0f, 1.0f,
	1.0f, -1.0f,  1.0f, 0.0f,
	1.0f,  1.0f,  1.0f, 1.0f
};
glm::vec4 lightPositionsOriginal[] = {
	glm::vec4(-3.0f, 1.0f, -2.0f, 0.0),
	glm::vec4(-1.0f, 1.0f, -2.0f, 0.0),
	glm::vec4( 1.0f, 1.0f, -2.0f, 0.0),
	glm::vec4( 3.0f, 1.0f, -2.0f, 0.0)
};
glm::vec4 lightPositions[] = {
	glm::vec4(-3.0f, 1.0f, -2.0f, 0.0),
	glm::vec4(-1.0f, 1.0f, -2.0f, 0.0),
	glm::vec4( 1.0f, 1.0f, -2.0f, 0.0),
	glm::vec4( 3.0f, 1.0f, -2.0f, 0.0)
};
glm::vec4 lightColors[] = {
	glm::vec4(0.25),
	glm::vec4(0.50),
	glm::vec4(0.75),
	glm::vec4(1.00)
};

#endif // !POSITIONS_H

