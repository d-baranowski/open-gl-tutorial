// Include GLEW Extension Wrangler
#include <GL/glew.h>

#ifndef OPEN_GL_TUTORIAL_MESH_H
#define OPEN_GL_TUTORIAL_MESH_H


class Mesh
{
public:
    Mesh();

    void create_mesh(GLfloat *vertices, unsigned int *indices, unsigned int num_of_vertices, unsigned int num_of_indices);

    void render_mesh();

    void clear_mesh();

    ~Mesh();

private:
    GLuint vertex_array_object_address, vertex_buffer_object_address, index_buffer_object_address;
    GLsizei index_count;
};


#endif //OPEN_GL_TUTORIAL_MESH_H
