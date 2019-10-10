#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


#ifndef OPEN_GL_TUTORIAL_WINDOW_H
#define OPEN_GL_TUTORIAL_WINDOW_H


class Window {
public:
    Window();
    int initialise();

    Window(GLint windowWidth, GLint windowHeight);

    GLint getBufferWidth() { return bufferWidth;}
    GLint getBufferHeight() { return bufferHeight;}

    bool getShouldClose() { return glfwWindowShouldClose(mainWindow); }

    void swapBuffers() { glfwSwapBuffers(mainWindow); }

    ~Window();

private:
    GLFWwindow *mainWindow;
    GLint  width, height;
    GLint bufferWidth, bufferHeight;
};


#endif //OPEN_GL_TUTORIAL_WINDOW_H
