#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


#ifndef OPEN_GL_TUTORIAL_WINDOW_H
#define OPEN_GL_TUTORIAL_WINDOW_H


class Window
{
public:
    Window();

    void initialise();

    bool* get_keys() { return keys; };
    GLfloat get_x_change();
    GLfloat get_y_change();

    Window(GLint window_width, GLint window_height);

    GLint get_buffer_width()
    { return buffer_width; }

    GLint get_buffer_height()
    { return buffer_height; }

    bool get_should_close()
    { return static_cast<bool>(glfwWindowShouldClose(main_window)); }

    void swap_buffers()
    { glfwSwapBuffers(main_window); }

    ~Window();

private:
    GLFWwindow *main_window;
    GLint width, height;
    GLint buffer_width, buffer_height;
    bool keys[1024]; // ASCII range
    GLfloat last_x, last_y, x_change, y_change;
    bool mouse_first_moved;

    void create_callbacks();

    static void handle_keys(GLFWwindow *window, int key, int code, int action, int mode);

    static void handle_mouse(GLFWwindow *window, double x_pos, double y_pos);
};


#endif //OPEN_GL_TUTORIAL_WINDOW_H
