#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>
#include <src/Mesh.h>
#include <src/Window.h>
#include <src/Shader.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const auto TO_RADIANS = static_cast<const float>(3.1415926535 / 180.0f); // Multiply by this to get a radians from angle

Window MAIN_WINDOW;
std::vector<Mesh *> MESH_LIST;
std::vector<Shader *> SHADER_LIST;

static const char *V_SHADER = "src/shaders/vertex.glsl";
static const char *F_SHADER = "src/shaders/fragment.glsl";

void create_triangle()
{
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
    obj->create_mesh(vertices, indices, 12, 12);
    MESH_LIST.push_back(obj);
}

void create_shader()
{
    auto *shader = new Shader();
    shader->create_from_files(V_SHADER, F_SHADER);
    SHADER_LIST.push_back(shader);
}

int main()
{
    MAIN_WINDOW = Window(800, 600);
    MAIN_WINDOW.initialise();

    create_shader();
    create_triangle();

    glm::mat4 projection = glm::perspective(45.0f, (GLfloat) MAIN_WINDOW.get_buffer_width() /
                                                   (GLfloat) MAIN_WINDOW.get_buffer_height(), 0.1f, 100.0f);

    glClearColor(0.5f, 0.5f, 0.4f, 0.0f);

    while (!MAIN_WINDOW.get_should_close())
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        SHADER_LIST[0]->use_shader();

        glm::mat4 model;

        // Rotate around y axis by
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3));
        model = glm::rotate(model, 360 * 0.0f * TO_RADIANS, glm::vec3(0, 1, 0));
        model = glm::rotate(model, 360 * 0.0f * TO_RADIANS, glm::vec3(0, 0, 1));
        model = glm::scale(model, glm::vec3(0.4, 0.4, 1));

        GLuint uniform_model, uniform_projection;

        uniform_model = SHADER_LIST[0]->get_model_location();
        uniform_projection = SHADER_LIST[0]->get_projection_location();

        glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniform_projection, 1, GL_FALSE, glm::value_ptr(projection));

        MESH_LIST[0]->render_mesh();

        glUseProgram(0);

        // Swap buffers
        MAIN_WINDOW.swap_buffers();
    }

    return 0;
}

