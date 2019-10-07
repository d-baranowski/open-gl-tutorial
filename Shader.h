#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

#ifndef OPEN_GL_TUTORIAL_SHADER_H
#define OPEN_GL_TUTORIAL_SHADER_H


class Shader {
public:
    Shader();

    void CreateFromString(const char* vertexCode, const char* fragmentCode);

    GLuint GetProjectionLocation();
    GLuint GetModelLocation();

    void UserShader();
    void ClearShader();

    ~Shader();

private:
    GLuint shaderId, uniformProjection, uniformModel;

    void CompileShader(const char* vertexCode, const char* fragmentCode);
    void AddShader(GLuint theProgram, const char * shaderCode, GLenum shaderType);
};


#endif //OPEN_GL_TUTORIAL_SHADER_H
