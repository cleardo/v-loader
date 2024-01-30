#pragma once
#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>

namespace GLPL {

	class MyDrawable {
	public:
		MyDrawable();

		void createAndSetupBuffers();
		void drawBoundingBox();

	protected:
		// Buffers
		GLuint VAO, VBO;

		// Area
		std::vector<GLfloat> boxVerts = { -1, -1,    1, -1,    1,  1,    -1, 1 };

		glm::vec4 boundingBoxColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	};
}
