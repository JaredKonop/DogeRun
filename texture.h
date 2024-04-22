#pragma once
#include "GameManager.h"
class Texture
{
private:
	static GLuint shaderProgram, VBO, VAO;
	static const GLchar* vertexShaderSource;
	static const GLchar* fragmentShaderSource;
public:
	static void init();
	static GLuint createProgram();
	static GLuint load(const char* file);
	static void render(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLuint texture);
};