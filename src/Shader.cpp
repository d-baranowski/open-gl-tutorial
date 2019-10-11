//
// Created by Daniel Baranowski on 2019-10-07.
//

#include "Shader.h"

Shader::Shader()
{
    shader_id = 0;
    uniform_model = 0;
    uniform_projection = 0;
}

void Shader::compile_shader(const char *vertexCode, const char *fragmentCode)
{
    shader_id = glCreateProgram();

    if (!shader_id)
    {
        printf("Error creating shader");
        return;
    }

    add_shader(shader_id, vertexCode, GL_VERTEX_SHADER);
    add_shader(shader_id, fragmentCode, GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar eLog[1024] = {0};

    // Create executables on the graphics card
    glLinkProgram(shader_id);

    // Validate if compiled and linked correctly

    // Get program link status
    glGetProgramiv(shader_id, GL_LINK_STATUS, &result);

    if (!result)
    {
        glGetProgramInfoLog(shader_id, sizeof(eLog), nullptr, eLog);
        printf("Error linking program: %s\n", eLog);
        return;
    }


    GLuint temp;
    glGenVertexArrays(1, &temp);
    glBindVertexArray(temp);
    glValidateProgram(shader_id);
    glDeleteVertexArrays(1, &temp);

    // Get program validation status
    glGetProgramiv(shader_id, GL_VALIDATE_STATUS, &result);

    if (!result)
    {
        glGetProgramInfoLog(shader_id, sizeof(eLog), nullptr, eLog);
        printf("Program is not valid: %s\n", eLog);
        return;
    }

    uniform_model = static_cast<GLuint>(glGetUniformLocation(shader_id, "model"));
    uniform_projection = static_cast<GLuint>(glGetUniformLocation(shader_id, "projection"));
}

void Shader::add_shader(GLuint theProgram, const char *shader_code, GLenum shader_type)
{
    GLuint shader = glCreateShader(shader_type);

    const GLchar *code[1];
    code[0] = shader_code;

    GLint code_length[1];
    code_length[0] = static_cast<GLint>(strlen(shader_code));

    // Load in the source code
    glShaderSource(shader, 1, code, code_length);

    // Compile the source code
    glCompileShader(shader);

    // Error check
    GLint result = 0;
    GLchar e_log[1024] = {0};


    // Validate if compiled and linked correctly

    // Get program link status
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

    if (!result)
    {
        glGetShaderInfoLog(shader, sizeof(e_log), nullptr, e_log);
        printf("Error compiling %u shader program: %s\n", shader_type, e_log);
        return;
    }

    glAttachShader(theProgram, shader);
}

void Shader::use_shader()
{
    glUseProgram(shader_id);
}

void Shader::clear_shader()
{
    if (shader_id != 0)
    {
        glDeleteProgram(shader_id);
        shader_id = 0;
    }

    uniform_model = 0;
    uniform_projection = 0;
}

Shader::~Shader()
{
    clear_shader();
}

GLuint Shader::get_model_location()
{
    return uniform_model;
}

GLuint Shader::get_projection_location()
{
    return uniform_projection;
}

void Shader::create_from_files(const char *vertex_file_path, const char *fragment_file_path)
{
    std::string vertex_string = read_file(vertex_file_path);
    std::string fragment_string = read_file(fragment_file_path);

    compile_shader(vertex_string.c_str(), fragment_string.c_str());
}

std::string Shader::read_file(const char *file_location)
{
    std::string content;
    std::ifstream fileStream(file_location, std::ios::in);

    if (!fileStream.is_open())
    {
        printf("Failed to read %s file", file_location);
    }

    std::string line = line;
    while (!fileStream.eof())
    {
        std::getline(fileStream, line);
        content.append(line + "\n ");
    }

    fileStream.close();
    return content;
}
