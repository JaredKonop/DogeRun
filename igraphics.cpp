
#include "GameManager.h"

extern GameManager game;
GLFWwindow* iG::window;
GLuint iG::iWindowWidth;
GLuint iG::iWindowHeight;
GLfloat iG::iWindowX;
GLfloat iG::iWindowY;
GLuint iG::iScreenWidth;
GLuint iG::iScreenHeight;
GLfloat iG::iClearR;
GLfloat iG::iClearG;
GLfloat iG::iClearB;
vector<iG::vertice> iG::vertices;
GLfloat iG::r, iG::g, iG::b, iG::a;
GLuint iG::shaderProgram, iG::VBO, iG::VAO;
const GLchar* iG::vertexShaderSource = "#version 430 core\n"
"layout (location = 0) in vec2 aPos;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"   gl_Position =  projection * vec4(aPos,0.0, 1.0);\n"
"}";

const GLchar* iG::fragmentShaderSource = "#version 430 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor;\n"
"}";
void update();
void iG::iInitialize(const char* title)
{
	if (!glfwInit()) { exit(EXIT_FAILURE); }
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(iG::iGetWindowWidth(), iG::iGetWindowHeight(), "DogeRun", glfwGetPrimaryMonitor(), NULL);
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }

	glfwSetKeyCallback(window, iKeyboard);	// Callback for keyboard interactions
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);	  // Hide the cursor
	
	glLineWidth(2.0f);	 // Drawing line width
	glEnable(GL_LINE_SMOOTH);	// Makes line smoother

	glEnable(GL_BLEND);     // Transparent Color
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // Transparent Color

	iG::start();
	game.init();

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		iDraw();
		update();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	iG::end();

	glfwTerminate();
	glfwDestroyWindow(window);
	exit(EXIT_SUCCESS);
}
