#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

#ifndef OPEN_GL_TUTORIAL_SHADER_H
#define OPEN_GL_TUTORIAL_SHADER_H


class Shader
{
public:
    Shader();

    void create_from_files(const char *vertex_file_path, const char *fragment_file_path);

    static std::string read_file(const char *file_location);

    GLuint get_projection_location();

    GLuint get_model_location();

    GLuint get_view_location();

    void use_shader();

    void clear_shader();

    ~Shader();

private:
    GLuint shader_id, uniform_projection, uniform_model, uniform_view;

    void compile_shader(const char *vertexCode, const char *fragmentCode);

    static void add_shader(GLuint theProgram, const char *shader_code, GLenum shader_type);
};


#endif //OPEN_GL_TUTORIAL_SHADER_H
