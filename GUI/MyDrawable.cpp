#include "MyDrawable.h"
#include "../rendering/shader.h"
#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>



GLPL::MyDrawable::MyDrawable()
{
}

void GLPL::MyDrawable::createAndSetupBuffers() {
    // Bounding Box
    // Create Buffers
    glGenBuffers(1, &VBO);

    glGenVertexArrays(1, &VAO);

    // Setup Buffers
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, boxVerts.size() * sizeof(GLfloat), &boxVerts[0], GL_STATIC_DRAW);

    // Position Attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

    glBindVertexArray(0);

    // Bounding Box With Children
    // Create Buffers
    // glGenVertexArrays(1, &mouseVAO);
    // glGenBuffers(1, &mouseVBO);

    // Setup Buffers
    // glBindVertexArray(mouseVAO);
    // glBindBuffer(GL_ARRAY_BUFFER, mouseVBO);
    // glBufferData(GL_ARRAY_BUFFER, mouseOverVertsWithChildren.size() * sizeof(GLfloat), &mouseOverVertsWithChildren[0], GL_STATIC_DRAW);

    // Position Attributes
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

    glBindVertexArray(0);
}

void GLPL::MyDrawable::drawBoundingBox()
{
    // glm::vec4 myVect;

    // Draw bounding box
    // std::shared_ptr<Shader> shader = shaderSetPt->getPlot2dShader();
    GLPL::Shader plot2dShader = GLPL::Shader("Shaders/plot2d.vs", "Shaders/plot2d.frag");

    GLPL::Shader* shader = &plot2dShader;

    shader->Use();

    glm::mat4 identMatrix = glm::mat4(1.0f);

    glm::mat4 overallTransform = glm::scale(identMatrix, glm::vec3(0.5f, 0.5f, 0.5f));

    glUniformMatrix4fv(glGetUniformLocation(shader->Program, "transformViewport"), 1, GL_FALSE, glm::value_ptr(overallTransform));

    glUniform4fv(glGetUniformLocation(shader->Program, "inColor"), 1, glm::value_ptr(boundingBoxColor));

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    glBindVertexArray(0);

    // Draw bounding box of children
    /*
    for (auto& i : children) {
        i->drawBoundingBox();
    }
    */
}
