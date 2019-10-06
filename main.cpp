// Include standard input output
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4


// Include GLEW Extension Wrangler
#include <GL/glew.h>

// Include GLFW Frame Work
#include <GLFW/glfw3.h>


const GLint WIDTH = 800, HEIGHT = 600;
const float toRadians = 3.1415926535 / 180.0f; // Multiply by this to get a radians from angle

GLuint VAO, VBO, IBO, shader, uniformModel, uniformProjection;

bool direction = true;
float triOffset = 0.0f;
float triMaxOffset = 0.7f;
float triIncrement  = 0.005f;


// Vertex shader
// GL(SL) Shader Language version
// Return value of the vertex shader 1 vertex -> 1 position
static const char* vShader = R""""(
#version 330
layout (location = 0) in vec3 pos;

out vec4 vColor;
uniform mat4 model;
uniform mat4 projection;

void main()
{
  gl_Position = projection * model * vec4(pos, 1.0);
  vColor = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
}
)"""";

// Fragment shader
// GL(SL) Shader Language version
// For this shader it only has 1 out value so every name works in this case
// Return value of the vertex shader 1 vertex -> 1 position
static const char* fShader = R""""(
#version 330

in vec4 vColor;
out vec4 color;

void main()
{
  color = vColor;
}
)"""";

void CreateTriangle()
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

    // Create a vertex array on the graphics card and store the id in programs memory
    glGenVertexArrays(1, &VAO);
    // Now all the vertex operations in OpenGL will refer to that vertex array
    glBindVertexArray(VAO);

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glGenBuffers(1, &VBO);
    // You need to specify what type of buffer you're binding
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Send data to Vertex Buffer, since image won't move we use GL_STATIC_DRAW
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 0 corresponds to vertex shader layout 0,
    // 3 determines that each vertex has three values xyz
    // Type of the values
    // Specify if values should be normalised
    // Specify whats the stride between sets of values
    // Specify the offset of the first value from the start
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
}

void AddShader(GLuint theProgram, const char * shaderCode, GLenum shaderType)
{
    GLuint theShader = glCreateShader(shaderType);

    const GLchar *theCode[1];
    theCode[0] = shaderCode;

    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);

    // Load in the source code
    glShaderSource(theShader, 1, theCode, codeLength);

    // Compile the source code
    glCompileShader(theShader);

    // Error check
    GLint result = 0;
    GLchar eLog[1024] = { 0 };


    // Validate if compiled and linked correctly

    // Get program link status
    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);

    if (!result)
    {
        glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
        printf("Error compiling %u shader program: %s\n", shaderType, eLog);
        return;
    }

    glAttachShader(theProgram, theShader);
}

void CompileShaders()
{
    shader = glCreateProgram();

    if (!shader)
    {
        printf("Error creating shader");
        return;
    }

    AddShader(shader, vShader, GL_VERTEX_SHADER);
    AddShader(shader, fShader, GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    // Create executables on the graphics card
    glLinkProgram(shader);

    // Validate if compiled and linked correctly

    // Get program link status
    glGetProgramiv(shader, GL_LINK_STATUS, &result);

    if (!result)
    {
        glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
        printf("Error linking program: %s\n", eLog);
        return;
    }

    glValidateProgram(shader);

    // Get program validation status
    glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);

    if (!result)
    {
        glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
        printf("Program is not valid: %s\n", eLog);
        return;
    }

    uniformModel = glGetUniformLocation(shader, "model");
    uniformProjection =  glGetUniformLocation(shader, "projection");
}

int main(void) {
    // Initialise GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return -1;
    }


    // Setup GLFW window properties
    // Set GLFW version to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Set to be not backwards compatible
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // but forwards compatible
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Open a window and create its OpenGL context
    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);

    if (mainWindow == NULL) {
        fprintf(stderr,
                "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // Get Buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Set context for GLEW to use
    glfwMakeContextCurrent(mainWindow);

    // Allow modern features
    glewExperimental = GL_TRUE;

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    // Setup Viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    CreateTriangle();
    CompileShaders();

    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)bufferWidth / (GLfloat)bufferHeight, 0.1f, 100.0f);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(mainWindow, GLFW_STICKY_KEYS, GL_TRUE);


    glClearColor(0.5f, 0.5f, 0.4f, 0.0f);

    while (glfwGetKey(mainWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(mainWindow) == 0) {
        glfwPollEvents();

        if (direction)
        {
            triOffset += triIncrement;
        } else
        {
            triOffset -= triIncrement;
        }

        if (abs(triOffset) > triMaxOffset)
        {
            direction = !direction;
        }

        // Clear the colors buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shader);

        glm::mat4 model;

        // Rotate around y axis by
        model = glm::translate(model,  glm::vec3(0,0,-3));
        model = glm::rotate(model,  360 * triOffset * toRadians, glm::vec3(0,1,0));
        model = glm::scale(model, glm::vec3(0.4, 0.4, 0.4));




        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);


        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glUseProgram(0);

        // Swap buffers
        glfwSwapBuffers(mainWindow);

    }

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

