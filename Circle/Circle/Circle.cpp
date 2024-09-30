#define _USE_MATH_DEFINES 

#include <iostream>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "error.h"
#include "file.h"
#include "shader.h"


#define NUM_BUFFERS 1
#define NUM_VAOS 1
GLuint Buffers[NUM_BUFFERS];
GLuint VAOs[NUM_VAOS];

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

}

void ResizeCallback(GLFWwindow*, int w, int h)
{
	glViewport(0, 0, w, h);
}


#define DEG2RAD(n)	n*(M_PI/180)

float* CreateCircle(int num_segments, float radius)
{
	// Allocate memory for dynamic array of vertices
	//float* vertices = new float[num_segments * 3 * 3]; // Each vertex has 3 components (x, y, z)
	float* vertices = (float*)malloc(sizeof(float) * 3 * num_segments * 3);
	// Calculate the angular offset
	float offset = 360.0f / num_segments;

	// Initialize angle
	float angle = 0.0f;

	// Generate vertices for each segment
	for (int i = 0; i < num_segments; ++i) {
		// Calculate indices for vertices of the current segment
		int index = i * 3 * 3; // Each vertex has 3 components (x, y, z)
		float rad_angle = angle * (M_PI / 180.0);
		float rad_next_angle = (angle + offset) * (M_PI / 180.0);
		// Specify vertex v0 as the center of the circle (0, 0, 0)
		vertices[index] = 0.0f;
		vertices[index + 1] = 0.0f;
		vertices[index + 2] = 0.0f;

		// Specify vertex v1 using angle
		vertices[index + 3] = radius * cos(rad_angle); // x
		//std::cout << "index " << index + 3 << " is \n" << cos(DEG2RAD(angle)) << std::endl;
		vertices[index + 4] = radius * sin(rad_angle); // y
		vertices[index + 5] = 0.0f; // z

		// Specify vertex v2 using (angle + offset)
		vertices[index + 6] = radius * cos(rad_next_angle); // x
		//std::cout << "index " << index + 6 << " is \n" << cos(DEG2RAD(angle + offset)) << std::endl;
		vertices[index + 7] = radius * sin(rad_next_angle); // y
		vertices[index + 8] = 0.0f; // z

		// Update angle
		angle += offset;
	}

	return vertices;

}

int main()
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(640, 480, "2D modelling", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetWindowSizeCallback(window, ResizeCallback);

	gl3wInit();


	GLuint program = CompileShader("triangle.vert", "triangle.frag");
	int num_segments = 32;

	float* vertices = CreateCircle(num_segments, 1.f);

	glCreateBuffers(NUM_BUFFERS, Buffers);

	glNamedBufferStorage(Buffers[0], (num_segments * 3 * 3 * sizeof(float)), vertices, 0);
	glGenVertexArrays(NUM_VAOS, VAOs);
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3 * sizeof(float)), (void*)0);
	glEnableVertexAttribArray(0);


	while (!glfwWindowShouldClose(window))
	{
		static const GLfloat bgd[] = { 1.f, 1.f, 1.f, 1.f };
		glClearBufferfv(GL_COLOR, 0, bgd);

		glUseProgram(program);
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, num_segments * 3);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	free(vertices);

	glfwDestroyWindow(window);
	glfwTerminate();
}