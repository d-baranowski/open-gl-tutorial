//
// Created by Daniel Baranowski on 2019-10-07.
//

#include "Shader.h"

Shader::Shader() {
    shaderId = 0;
    uniformModel = 0;
    uniformProjection = 0;
}

void Shader::CompileShader(const char *vertexCode, const char *fragmentCode) {
    shaderId = glCreateProgram();

    if (!shaderId) {
        printf("Error creating shader");
        return;
    }

    AddShader(shaderId, vertexCode, GL_VERTEX_SHADER);
    AddShader(shaderId, fragmentCode, GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar eLog[1024] = {0};

    // Create executables on the graphics card
    glLinkProgram(shaderId);

    // Validate if compiled and linked correctly

    // Get program link status
    glGetProgramiv(shaderId, GL_LINK_STATUS, &result);

    if (!result) {
        glGetProgramInfoLog(shaderId, sizeof(eLog), nullptr, eLog);
        printf("Error linking program: %s\n", eLog);
        return;
    }


    GLuint temp;
    glGenVertexArrays(1, &temp);
    glBindVertexArray(temp);
    glValidateProgram(shaderId);
    glDeleteVertexArrays(1, &temp);

    // Get program validation status
    glGetProgramiv(shaderId, GL_VALIDATE_STATUS, &result);

    if (!result) {
        glGetProgramInfoLog(shaderId, sizeof(eLog), nullptr, eLog);
        printf("Program is not valid: %s\n", eLog);
        return;
    }

    uniformModel = static_cast<GLuint>(glGetUniformLocation(shaderId, "model"));
    uniformProjection = static_cast<GLuint>(glGetUniformLocation(shaderId, "projection"));
}

void Shader::AddShader(GLuint theProgram, const char *shaderCode, GLenum shaderType) {
    GLuint theShader = glCreateShader(shaderType);

    const GLchar *theCode[1];
    theCode[0] = shaderCode;

    GLint codeLength[1];
    codeLength[0] = static_cast<GLint>(strlen(shaderCode));

    // Load in the source code
    glShaderSource(theShader, 1, theCode, codeLength);

    // Compile the source code
    glCompileShader(theShader);

    // Error check
    GLint result = 0;
    GLchar eLog[1024] = {0};


    // Validate if compiled and linked correctly

    // Get program link status
    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);

    if (!result) {
        glGetShaderInfoLog(theShader, sizeof(eLog), nullptr, eLog);
        printf("Error compiling %u shader program: %s\n", shaderType, eLog);
        return;
    }

    glAttachShader(theProgram, theShader);
}

void Shader::UserShader() {
    glUseProgram(shaderId);
}

void Shader::ClearShader() {
    if (shaderId != 0) {
        glDeleteProgram(shaderId);
        shaderId = 0;
    }

    uniformModel = 0;
    uniformProjection = 0;
}

Shader::~Shader() {
    ClearShader();
}

GLuint Shader::GetModelLocation() {
    return uniformModel;
}

GLuint Shader::GetProjectionLocation() {
    return uniformProjection;
}

void Shader::CreateFromFiles(const char *vertexFilePath, const char *fragmentFilePath) {
    std::string vertexString = ReadFile(vertexFilePath);
    std::string fragmentString = ReadFile(fragmentFilePath);

    CompileShader(vertexString.c_str(), fragmentString.c_str());
}

std::string Shader::ReadFile(const char *fileLocation) {
    std::string content;
    std::ifstream fileStream(fileLocation, std::ios::in);

    if (!fileStream.is_open()) {
        printf("Failed to read %s file", fileLocation);
    }

    std::string line = line;
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n ");
    }

    fileStream.close();
    return content;
}
