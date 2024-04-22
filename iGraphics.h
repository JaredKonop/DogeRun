#ifndef __I_GRAPHICS__
#define __I_GRAPHICS__
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <windows.h>
#include <mmsystem.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <tuple>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>

#define PI (acos(-1.0))
using namespace std;

class iG
{
public:
	static GLFWwindow* window;
	static GLuint iWindowHeight, iWindowWidth, iScreenHeight, iScreenWidth;
	static GLfloat iWindowX, iWindowY;
	static GLfloat iClearR, iClearG, iClearB;
	struct vertice
	{
		GLfloat x, y;
	};
	static vector<vertice> vertices;
	static GLfloat r, g, b, a;
	static const GLchar* vertexShaderSource;
	static const GLchar* fragmentShaderSource;

	static GLuint shaderProgram, VBO, VAO;
	static GLuint createProgram()
	{
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		// fragment shader
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		// link shaders
		GLuint shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return shaderProgram;
	}
	
	static void start()
	{
		r = g = b = 0.0f;
		a = 1.0f;
		shaderProgram = createProgram();
		glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(iG::iScreenWidth), 0.0f, static_cast<float>(iG::iScreenHeight));
		glUseProgram(shaderProgram);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
	}

	static void iKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void iDraw();

	static void draw()
	{
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*2*vertices.size() , &vertices[0], GL_STATIC_DRAW);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*2, (void*)0);
		glEnableVertexAttribArray(0);

		glUseProgram(shaderProgram);
		glUniform4f(glGetUniformLocation(shaderProgram, "ourColor"), r, g, b, a);
		glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());
		glUniform4f(glGetUniformLocation(shaderProgram, "ourColor"), 0.0f, 0.0f, 0.0f, a);
		glDrawArrays(GL_LINE_LOOP, 0, vertices.size());

		vertices.clear();
	}

	static void end()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteProgram(shaderProgram);
	}
	static void iSetColor(tuple<GLfloat, GLfloat, GLfloat> rgb)
	{
		r = get<0>(rgb) / 255;
		g = get<1>(rgb) / 255;
		b = get<2>(rgb) / 255;
	}
	static void iSetColor(GLfloat red, GLfloat green, GLfloat blue,GLfloat alpha=1.0)
	{
		r = red / 255;
		g = green / 255;
		b = blue / 255;
		a = alpha;
	}
	static void iSetBGColor(GLfloat r, GLfloat g, GLfloat b)
	{
		iClearR = r / 255;
		iClearG = g / 255;
		iClearB = b / 255;
	}
	static void iClear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(iClearR, iClearG, iClearB, 1.0);
	}

	static void iPolygon(GLfloat* x, GLfloat* y, GLint size)
	{
		for (int i = 0;i < size;i++)
		{
			vertices.push_back({ x[i], y[i] });
		}
		draw();
	}

	static void iCircle(GLfloat x, GLfloat y, GLfloat r, GLint slices = 100)
	{
		GLfloat t, dt = 2 * PI / slices;
		for (t = 0; t <= 2 * PI + dt; t += dt)
		{
			GLfloat x1, y1;
			x1 = (x + r * cos(t)) ;
			y1 = (y + r * sin(t)) ,
				vertices.push_back({ x1, y1 });
		}
		draw();
	}

	static void iRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
	{
		GLfloat x1, x2, y1, y2;
		x1 = x ,
		y1 = y ,
		x2 = ((x + width) ) ,
		y2 = ((y + height) );

		vertices.push_back({ x1, y1 });
		vertices.push_back({ x2, y1 });
		vertices.push_back({ x2, y2 });
		vertices.push_back({ x1, y2 });
		draw();
	}

	static GLint iGetWindowHeight()
	{
		return iWindowHeight;
	}
	static GLint iGetWindowWidth()
	{
		return iWindowWidth;
	}
	static void iSetWindowHeight(GLint height)
	{
		iWindowHeight = height;
	}
	static void iSetWindowWidth(GLint width)
	{
		iWindowWidth = width;
	}
	static GLint iGetScreenHeight()
	{
		return iScreenHeight;
	}
	static GLint iGetScreenWidth()
	{
		return iScreenWidth;
	}
	static void iSetScreenHeight(GLint height)
	{
		iScreenHeight = height;
	}
	static void iSetScreenWidth(GLint width)
	{
		iScreenWidth = width;
	}
	static void iSetWindowX(GLfloat x)
	{
		iWindowX = x;
	}
	static void iSetWindowY(GLfloat y)
	{
		iWindowY = y;
	}
	static void windowSetup();
	static void iInitialize(const char* title);
};
#endif