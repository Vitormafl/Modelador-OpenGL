#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include"Shaders/shaderClass.h"
#include"Objects/VAO.h"
#include"Objects/VBO.h"
#include"Objects/EBO.h"

GLfloat vertices[] =
{
	-0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,   // Front Lower left corner
	 0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,   // Front Lower right corner
	 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,   // Front Upper right corner
	-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,   // Front Upper left corner
	-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,   // Back Lower left corner
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,   // Back Lower right corner
	 0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,   // Back Upper right corner
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,   // Back Upper left corner
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1,
	1, 2,
	2, 3,
	3, 0,
	0, 4,
	1, 5,
	2, 6,
	3, 7,
	4, 5,
	5, 6,
	6, 7,
	7, 4

};

GLuint indices2[] =
{
	2, 3, 1,
	0, 1, 3
};



int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Modelador - Octree", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, 800, 800);

	Shader shaderProgram("Shaders/default.vert", "Shaders/default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttribute(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttribute(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*) (3 * sizeof(float)));

	VAO1.Unbind();
	EBO1.Unbind();
	VBO1.Unbind();

	//Inicializando uniforms
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	glEnable(GL_DEPTH_TEST);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		//Mandando a uniform para o shader
		glUniform1f(uniID, 4.5f);

		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= (1.0f / 60.0f))
		{
			rotation += 0.5f;
			prevTime = crntTime;
		}

		glm::mat4 model(1.0f);
		glm::mat4 view(1.0f);
		glm::mat4 proj(1.0f);

		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(-0.0f, -0.0f, -50.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)(800 / 800), 0.1f, 100.0f);

		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_LINES, 24, GL_UNSIGNED_INT, 0);
		VAO1.Unbind();

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}