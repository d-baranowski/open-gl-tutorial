#include "Mesh.h"

Mesh::Mesh()
{
    vertex_array_object_address = 0;
    vertex_buffer_object_address = 0;
    index_buffer_object_address = 0;
    index_count = 0;
}

void Mesh::create_mesh(GLfloat *vertices, unsigned int *indices, unsigned int num_of_vertices, unsigned int num_of_indices)
{
    index_count = num_of_indices;

    glGenVertexArrays(1, &vertex_array_object_address);
    glBindVertexArray(vertex_array_object_address);

    glGenBuffers(1, &index_buffer_object_address);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_object_address);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * num_of_indices, indices, GL_STATIC_DRAW);

    glGenBuffers(1, &vertex_buffer_object_address);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object_address);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * num_of_vertices, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void Mesh::render_mesh()
{
    glBindVertexArray(vertex_array_object_address);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_object_address);
    glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::clear_mesh()
{
    if (index_buffer_object_address != 0)
    {
        glDeleteBuffers(1, &index_buffer_object_address);
        index_buffer_object_address = 0;
    }

    if (vertex_buffer_object_address != 0)
    {
        glDeleteBuffers(1, &vertex_buffer_object_address);
        vertex_buffer_object_address = 0;
    }

    if (vertex_array_object_address != 0)
    {
        glDeleteVertexArrays(1, &vertex_array_object_address);
        vertex_array_object_address = 0;
    }

    index_count = 0;
}


Mesh::~Mesh()
{
    clear_mesh();
}
