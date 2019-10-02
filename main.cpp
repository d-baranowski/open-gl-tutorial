// Include standard input output
#include <stdio.h>

// Include GLEW Extension Wrangler
#include <GL/glew.h>

// Include GLFW Frame Work
#include <GLFW/glfw3.h>


const GLint WIDTH = 800, HEIGHT = 600;

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

    // Setup Viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(mainWindow, GLFW_STICKY_KEYS, GL_TRUE);


    glClearColor(0.5f, 0.5f, 0.4f, 0.0f);

    while (glfwGetKey(mainWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(mainWindow) == 0) {
        // Clear the colors buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw nothing, see you in tutorial 2 !


        // Swap buffers
        glfwSwapBuffers(mainWindow);
        glfwPollEvents();

    }

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

