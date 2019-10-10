#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

#ifndef OPEN_GL_TUTORIAL_SHADER_H
#define OPEN_GL_TUTORIAL_SHADER_H


class Shader {
public:
    Shader();

    void CreateFromFiles(const char *vertexFilePath, const char *fragmentFilePath);

    static std::string ReadFile(const char *fileLocation);

    GLuint GetProjectionLocation();

    GLuint GetModelLocation();

    void UserShader();

    void ClearShader();

    ~Shader();

private:
    GLuint shaderId, uniformProjection, uniformModel;

    void CompileShader(const char *vertexCode, const char *fragmentCode);

    static void AddShader(GLuint theProgram, const char *shaderCode, GLenum shaderType);
};


#endif //OPEN_GL_TUTORIAL_SHADER_H
