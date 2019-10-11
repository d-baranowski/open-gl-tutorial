#include "Window.h"

Window::Window()
{
    width = 800;
    height = 600;
}

Window::Window(GLint window_width, GLint window_height)
{
    width = window_width;
    height = window_height;
}

void Window::initialise()
{
    for (bool &key : keys)
    {
        key = false;
    }

    // Initialise GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
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
    main_window = glfwCreateWindow(width, height, "Test Window", nullptr, nullptr);

    if (main_window == nullptr)
    {
        fprintf(stderr,
                "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
    }

    glfwGetFramebufferSize(main_window, &buffer_width, &buffer_height);

    // Set context for GLEW to use
    glfwMakeContextCurrent(main_window);

    // Allow modern features
    glewExperimental = GL_TRUE;

    // Initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwDestroyWindow(main_window);
        glfwTerminate();
    }

    glEnable(GL_DEPTH_TEST);

    // Setup Viewport size
    glViewport(0, 0, buffer_width, buffer_height);

    glfwSetWindowUserPointer(main_window, this); // Makes it work with static callback
    glfwSetInputMode(main_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    create_callbacks();
}

Window::~Window()
{
    // Close OpenGL window and terminate GLFW
    glfwTerminate();
}

void Window::handle_keys(GLFWwindow *window, int key, int code, int action, int mode)
{
    auto *the_window = static_cast<Window *> (glfwGetWindowUserPointer(window));

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
        return;
    }

    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
        {
            the_window->keys[key] = true;
        } else if (action == GLFW_RELEASE)
        {
            the_window->keys[key] = false;
        }
    }
}

void Window::handle_mouse(GLFWwindow *window, double x_pos, double y_pos)
{
    auto *the_window = static_cast<Window *> (glfwGetWindowUserPointer(window));

    if (the_window->mouse_first_moved)
    {
        the_window->last_x = x_pos;
        the_window->last_y = y_pos;
        the_window->mouse_first_moved = false;
    }

    the_window->x_change = x_pos - the_window->last_x;
    the_window->y_change = the_window->last_y - y_pos;

    the_window->last_x = x_pos;
    the_window->last_y = y_pos;
}

void Window::create_callbacks()
{
    glfwSetKeyCallback(main_window, handle_keys);
    glfwSetCursorPosCallback(main_window, handle_mouse);
}

GLfloat Window::get_y_change()
{
    GLfloat temp = y_change;
    y_change = 0;
    return temp;
}

GLfloat Window::get_x_change()
{
    GLfloat temp = x_change;
    x_change = 0;
    return temp;
}
