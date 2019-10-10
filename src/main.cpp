#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>
#include <src/Mesh.h>
#include <src/Window.h>
#include <src/Shader.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const float toRadians = static_cast<const float>(3.1415926535 / 180.0f); // Multiply by this to get a radians from angle

Window mainWindow;
std::vector<Mesh *> meshList;
std::vector<Shader *> shaderList;

bool direction = true;

static const char *vShader = "src/shaders/vertex.glsl";
static const char *fShader = "src/shaders/fragment.glsl";

void CreateTriangle() {
    unsigned int indices[] = {
            0, 3, 1,
            1, 3, 2,
            2, 3, 0,
            0, 1, 2
    };

    GLfloat vertices[] = {
            -1.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 1.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
    };

    Mesh *obj = new Mesh();
    obj->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj);
}

void CreateShader() {
    auto *shader = new Shader();
    shader->CreateFromFiles(vShader, fShader);
    shaderList.push_back(shader);
}

int main() {
    mainWindow = Window(800, 600);
    mainWindow.initialise();

    CreateShader();
    CreateTriangle();

    glm::mat4 projection = glm::perspective(45.0f, (GLfloat) mainWindow.getBufferWidth() /
                                                   (GLfloat) mainWindow.getBufferHeight(), 0.1f, 100.0f);

    glClearColor(0.5f, 0.5f, 0.4f, 0.0f);

    while (!mainWindow.getShouldClose()) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderList[0]->UserShader();

        glm::mat4 model;

        // Rotate around y axis by
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3));
        model = glm::rotate(model, 360 * 0.0f * toRadians, glm::vec3(0, 1, 0));
        model = glm::rotate(model, 360 * 0.0f * toRadians, glm::vec3(0, 0, 1));
        model = glm::scale(model, glm::vec3(0.4, 0.4, 1));

        GLuint uniformModel, uniformProjection;

        uniformModel = shaderList[0]->GetModelLocation();
        uniformProjection = shaderList[0]->GetProjectionLocation();

        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

        meshList[0]->RenderMesh();

        glUseProgram(0);

        // Swap buffers
        mainWindow.swapBuffers();
    }

    return 0;
}

