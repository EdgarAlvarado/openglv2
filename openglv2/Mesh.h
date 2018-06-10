#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

struct Vertex 
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
};

struct Texture 
{
	GLuint id;
	string type;
	string path;
};

class Mesh
{
public:
	/* Mesh Data */
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;
	/* Functions */
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures)
	{
		this->vertices = vertices;
		this->indices = indices;
		this->textures = textures;

		setupMesh();
	}
	void Draw(Shader shader)
	{
		//setupMesh();
		GLuint diffuseNr = 0;
		GLuint specularNr = 0;
		GLuint normalNr = 0;
		GLuint heightNr = 0;
		for (GLuint i = 0; i < textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			string number;
			string name = textures[i].type;
			if ("texture_diffuse" == name)
				number = to_string(++diffuseNr);
			else if ("texture_specular" == name)
				number = to_string(++specularNr);
			else if ("texture_normal" == name)
				number = to_string(++normalNr);
			else if ("texture_height" == name)
				number = to_string(++heightNr);

			shader.setInt((name + number).c_str(), i);
			//std::cout << (name + number) << std::endl;
			glBindTexture(GL_TEXTURE_2D, textures[i].id);
		}

		// draw mesh
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
		//GLenum pepe = glGetError();
		glBindVertexArray(0);

		glActiveTexture(GL_TEXTURE0);
		//glDeleteVertexArrays(1, &VAO);
	}
	void DrawInstance(Shader shader, GLint amount)
	{
		GLuint diffuseNr = 0;
		GLuint specularNr = 0;
		GLuint normalNr = 0;
		GLuint heightNr = 0;
		for (GLuint i = 0; i < textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			string number;
			string name = textures[i].type;
			if ("texture_diffuse" == name)
				number = to_string(++diffuseNr);
			else if ("texture_specular" == name)
				number = to_string(++specularNr);
			else if ("texture_normal" == name)
				number = to_string(++normalNr);
			else if ("texture_height" == name)
				number = to_string(++heightNr);

			shader.setInt((name + number).c_str(), i);
			//std::cout << (name + number) << std::endl;
			glBindTexture(GL_TEXTURE_2D, textures[i].id);
		}

		// draw mesh
		glBindVertexArray(VAO);
		glDrawElementsInstanced(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0, amount);
		glBindVertexArray(0);

		glActiveTexture(GL_TEXTURE0);
	}
	void useVAO()
	{
		glBindVertexArray(VAO);
	}
private:
	/* Render data */
	GLuint VAO, VBO, EBO;
	/* Functions */
	void setupMesh()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		GLenum caca = glGetError();
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
		GLenum pepe = glGetError();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
		GLenum cool = glGetError();
		//Vertex positions
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		// Vertex normals
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
		// Vertex texture coords
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
		// Vertex tangent
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
		// Vertex normals
		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));

		glBindVertexArray(0);
	}
};

#endif // !MESH_H

