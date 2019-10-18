#ifndef OPEN_GL_TUTORIAL_CAMERA_H
#define OPEN_GL_TUTORIAL_CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class Camera
{
public:
    Camera() : Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, .5f) {
    };
    Camera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch, GLfloat move_speed, float d);
    ~Camera();

    void key_control(bool *keys, GLfloat delta_time);
    void mouse_control(GLfloat x_change, GLfloat y_change);
    glm::mat4 calculate_view_matrix();

private:
    glm::vec3 position, front, up, right; // camera positions
    glm::vec3 world_up;

    GLfloat yaw, pitch;
    GLfloat movement_speed{}, turn_speed{};

    void update();
};


#endif //OPEN_GL_TUTORIAL_CAMERA_H
