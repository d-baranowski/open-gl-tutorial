#include <printf.h>
#include <string>
#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch, GLfloat move_speed, GLfloat turn_speed)
{
    this->position = position;
    this->world_up = up;
    this->yaw = yaw;
    this->pitch = pitch;
    this->front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->movement_speed = move_speed;
    this->turn_speed = turn_speed;
    update();
}

void Camera::update()
{
    front.x = cos(glm::radians(yaw) * cos(glm::radians(pitch)));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(front);

    right = glm::normalize(glm::cross(front, world_up));
    up = glm::normalize(glm::cross(right, front));
}

void Camera::key_control(bool *keys, GLfloat delta_time)
{
    GLfloat velocity = movement_speed * delta_time;

    if (keys[GLFW_KEY_W])
    {
        position += front * velocity;
    }
    if (keys[GLFW_KEY_S])
    {
        position -= front * velocity;
    }
    if (keys[GLFW_KEY_A])
    {
        position -= right * velocity;
    }
    if (keys[GLFW_KEY_D])
    {
        position += right * velocity;
    }
}

glm::mat4 Camera::calculate_view_matrix()
{
    return glm::lookAt(position, position + front, up);
}

Camera::~Camera()
{
}

void Camera::mouse_control(GLfloat x_change, GLfloat y_change)
{
   x_change *= turn_speed;
   y_change *= turn_speed;

   yaw += x_change;
   pitch += y_change;

   if (pitch > 89.0f)
   {
        pitch = 89.0f;
   }

   if (pitch < -89.0f)
   {
       pitch = -89.0f;
   }
   update();
}
