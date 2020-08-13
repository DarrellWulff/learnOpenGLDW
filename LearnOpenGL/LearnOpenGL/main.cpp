#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// REMEMBER: you can use ifdef for platform specific compilation
	GLFWwindow* window = glfwCreateWindow(800, 600, "DWLearnGLRenderer", NULL, NULL);
	if (window == NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	//Callbacks in GLFW can be things like joystick input
	//Register callbacks before rendering after window is created.
	
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	
	//RENDER LOOP
	while (!glfwWindowShouldClose(window))
	{	
		//input
		processInput(window);

		// rendering 
		glClearColor(0.1f, 0.5f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//check and call events, swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) 
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}