#include "../Octree/OctreeRunnables.h"

#include "WingedEdge/Primitives/Model.h"
#include "CSG/Primitives/CSGTree.h"

#include <string>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

int main1() {
	//mev(int solidID, int face1ID, int face2ID, int existingVertexID, int ncwID, int pccwID, glm::vec3 newVertexCoordinates)
	//mef(int solidID, int existingFaceID, int startVertexID, int endVertexID, int ncwID, int pcwID, int nccwID, int pccwID)
	
	Model modelo = Model();
	modelo.msvf(glm::vec3());
	modelo.mev(0, 0, 0, 0, -1, -1, glm::vec3());
	modelo.mev(0, 0, 0, 1, 0, -1, glm::vec3());
	modelo.mev(0, 0, 0, 2, 1, -1, glm::vec3());
	modelo.mef(0, 0, 3, 0, 2, 0, -1, -1);
	modelo.mev(0, 1, 1, 3, 3, 2, glm::vec3());
	modelo.mev(0, 1, 1, 4, 4, -1, glm::vec3());
	modelo.mef(0, 1, 5, 0, 5, 3, 0, -1);
	modelo.mev(0, 2, 2, 2, 2, 1, glm::vec3());
	modelo.mef(0, 2, 6, 4, 7, 4, 5, -1);
	modelo.mev(0, 3, 3, 6, 8, 7, glm::vec3());
	modelo.mef(0, 3, 1, 7, 1, 9, -1, 0);
	modelo.mef(0, 4, 5, 7, 6, 10, 9, 5);

	std::cout << "VERTEX TABLE" << std::endl;
	for (int i = 0; i < modelo.solids[0].vertexTable.size(); i++)
		std::cout << "id: " << modelo.solids[0].vertexTable[i].id << " edge id: " << modelo.solids[0].vertexTable[i].incidentEdge << std::endl;
	std::cout << "" << std::endl;

	std::cout << "FACES TABLE" << std::endl;
	for (int i = 0; i < modelo.solids[0].faceTable.size(); i++)
		std::cout << "id: " << modelo.solids[0].faceTable[i].id << " edge id: " << modelo.solids[0].faceTable[i].incidentEdge << std::endl;
	std::cout << "" << std::endl;

	std::cout << "EDGE TABLE" << std::endl;
	for (int i = 0; i < modelo.solids[0].edgeTable.size(); i++)
		std::cout << "id: " << modelo.solids[0].edgeTable[i].id << " sv: " << modelo.solids[0].edgeTable[i].startVertex << " ev: " << modelo.solids[0].edgeTable[i].endVertex 
		<< " lf: " << modelo.solids[0].edgeTable[i].leftFace << " rf: " << modelo.solids[0].edgeTable[i].rightFace << " ncw: " << modelo.solids[0].edgeTable[i].ncw <<
		" pcw: " << modelo.solids[0].edgeTable[i].pcw << " nccw: " << modelo.solids[0].edgeTable[i].nccw << " pccw: " << modelo.solids[0].edgeTable[i].pccw << std::endl;
	std::cout << "" << std::endl;


	std::vector<GLuint> lineIndices;
	std::vector<GLfloat> vertices;

	for (int i = 0; i < modelo.solids[0].vertexTable.size(); i++) {
		vertices.push_back(modelo.solids[0].vertexTable[i].coordinates.x);
		vertices.push_back(modelo.solids[0].vertexTable[i].coordinates.y);
		vertices.push_back(modelo.solids[0].vertexTable[i].coordinates.z);
		vertices.push_back(1.0f);
		vertices.push_back(1.0f);
		vertices.push_back(1.0f);
	}

	for (int i = 0; i < modelo.solids[0].edgeTable.size(); i++) {
		lineIndices.push_back(modelo.solids[0].edgeTable[i].startVertex);
		lineIndices.push_back(modelo.solids[0].edgeTable[i].endVertex);
	}

	int verticesSize = (int)vertices.size();
	int indicesSize = (int)lineIndices.size();

	GLfloat* vertices1 = new GLfloat[verticesSize];
	GLuint* lineIndices1 = new GLuint[indicesSize];

	for (int i = 0; i < verticesSize; i++) {
		vertices1[i] = vertices[i];
	}

	for (int i = 0; i < indicesSize; i++) {
		lineIndices1[i] = lineIndices[i];
	}


	return 0;
}

// Vertices coordinates
//GLfloat vertices[] =
//{ //     COORDINATES     /        COLORS      
//	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,
//	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,
//	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,
//	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,
//	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f
//};
//
//// Indices for vertices order
//GLuint indices[] =
//{
//	1, 0, 2,
//	2, 0, 3,
//	1, 0, 4,
//	2, 1, 4,
//	3, 2, 4,
//	0, 3, 4
//};

int main()
{
	Model modelo = Model();
	modelo.msvf(glm::vec3(-1.0f, -1.0f, -1.0f));
	modelo.mev(0, 0, 0, 0, -1, -1, glm::vec3(1.0f, -1.0f, -1.0f));
	modelo.mev(0, 0, 0, 1, 0, -1, glm::vec3(1.0f, 1.0f, -1.0f));
	modelo.mev(0, 0, 0, 2, 1, -1, glm::vec3(-1.0f, 1.0f, -1.0f));
	modelo.mef(0, 0, 3, 0, 2, 0, -1, -1);
	modelo.mev(0, 1, 1, 3, 3, 2, glm::vec3(-1.0f, 1.0f, 1.0f));
	//modelo.mev(0, 1, 1, 4, 4, -1, glm::vec3(-1.0f, -1.0f, 1.0f));
	//modelo.mef(0, 1, 5, 0, 5, 3, 0, -1);
	//modelo.mev(0, 2, 2, 2, 2, 1, glm::vec3(1.0f, 1.0f, 1.0f));
	//modelo.mef(0, 2, 6, 4, 7, 4, 5, -1);
	//modelo.mev(0, 3, 3, 6, 8, 7, glm::vec3(1.0f, -1.0f, 1.0f));
	//modelo.mef(0, 3, 1, 7, 1, 9, -1, 0);
	//modelo.mef(0, 4, 5, 7, 6, 10, 9, 5);

	std::cout << "VERTEX TABLE" << std::endl;
	for (int i = 0; i < modelo.solids[0].vertexTable.size(); i++)
		std::cout << "id: " << modelo.solids[0].vertexTable[i].id << " edge id: " << modelo.solids[0].vertexTable[i].incidentEdge << std::endl;
	std::cout << "" << std::endl;

	std::cout << "FACES TABLE" << std::endl;
	for (int i = 0; i < modelo.solids[0].faceTable.size(); i++)
		std::cout << "id: " << modelo.solids[0].faceTable[i].id << " edge id: " << modelo.solids[0].faceTable[i].incidentEdge << std::endl;
	std::cout << "" << std::endl;

	std::cout << "EDGE TABLE" << std::endl;
	for (int i = 0; i < modelo.solids[0].edgeTable.size(); i++)
		std::cout << "id: " << modelo.solids[0].edgeTable[i].id << " sv: " << modelo.solids[0].edgeTable[i].startVertex << " ev: " << modelo.solids[0].edgeTable[i].endVertex
		<< " lf: " << modelo.solids[0].edgeTable[i].leftFace << " rf: " << modelo.solids[0].edgeTable[i].rightFace << " ncw: " << modelo.solids[0].edgeTable[i].ncw <<
		" pcw: " << modelo.solids[0].edgeTable[i].pcw << " nccw: " << modelo.solids[0].edgeTable[i].nccw << " pccw: " << modelo.solids[0].edgeTable[i].pccw << std::endl;
	std::cout << "" << std::endl;

	//std::cout << "ADJACENCIA VERTEX EDGE" << std::endl;
	//modelo.solids[0].edgeLoopVertex(0);
	//std::cout << "" << std::endl;
	//
	//std::cout << "ADJACENCIA FACE EDGE" << std::endl;
	//modelo.solids[0].edgeVertexLoop(4);
	//std::cout << "" << std::endl;


	std::vector<GLuint> lineIndices;
	std::vector<GLfloat> vertices;

	for (int i = 0; i < modelo.solids[0].vertexTable.size(); i++) {
		vertices.push_back(modelo.solids[0].vertexTable[i].coordinates.x);
		vertices.push_back(modelo.solids[0].vertexTable[i].coordinates.y);
		vertices.push_back(modelo.solids[0].vertexTable[i].coordinates.z);
		vertices.push_back(1.0f);
		vertices.push_back(1.0f);
		vertices.push_back(1.0f);
	}

	for (int i = 0; i < modelo.solids[0].edgeTable.size(); i++) {
		lineIndices.push_back(modelo.solids[0].edgeTable[i].startVertex);
		lineIndices.push_back(modelo.solids[0].edgeTable[i].endVertex);
	}

	int verticesSize = (int)vertices.size();
	int indicesSize = (int)lineIndices.size();

	GLfloat* vertices1 = new GLfloat[verticesSize];
	GLuint* lineIndices1 = new GLuint[indicesSize];

	for (int i = 0; i < verticesSize; i++) {
		vertices1[i] = vertices[i];
	}

	for (int i = 0; i < indicesSize; i++) {
		lineIndices1[i] = lineIndices[i];
	}


	/* GENERATING VERTICES AND INDICES ARRAYS */

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

	Shader shaderProgram("openGL/Shaders/default.vert", "openGL/Shaders/default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices1, verticesSize * 4);
	EBO EBO1(lineIndices1, indicesSize * 4);

	VAO1.LinkAttribute(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttribute(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	VAO1.Unbind();
	EBO1.Unbind();
	VBO1.Unbind();

	//Inicializando uniforms
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	bool testBool;

	//static const char* items[] = { "Item 1", "Item 2", "Item 3", "Item 4" };
	static int currentItem = 0;

	std::vector<Tables> items;

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
		glUniform1f(uniID, 2.5f);

		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= (1.0f / 60.0f))
		{
			rotation += 0.5f;
			prevTime = crntTime;
		}

		glm::mat4 model(1.0f);
		glm::mat4 view(1.0f);
		glm::mat4 proj(1.0f);

		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0000001f, 0.0f));
		view = glm::translate(view, glm::vec3(-0.0f, -1.0f, -15.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)(800 / 800), 0.1f, 100.0f);

		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_LINES, indicesSize, GL_UNSIGNED_INT, 0);

		VAO1.Unbind();
		// IMGUI COMPONENTS
		ImGui::Begin("My name is window, ImGUI window");
		ImGui::Text("Hello there adventurer!");
		ImGui::Checkbox("testCheckBox", &testBool);
		//ImGui::ListBox("Solids list", &currentItem, items, IM_ARRAYSIZE(items));
		ImGui::End();


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// Buffer and events stuff
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

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