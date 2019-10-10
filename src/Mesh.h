// Include GLEW Extension Wrangler
#include <GL/glew.h>

#ifndef OPEN_GL_TUTORIAL_MESH_H
#define OPEN_GL_TUTORIAL_MESH_H


class Mesh {
public:
    Mesh();

    void CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);
    void RenderMesh();
    void ClearMesh();

    ~Mesh();

private:
    GLuint VAO, VBO, IBO;
    GLsizei indexCount;
};


#endif //OPEN_GL_TUTORIAL_MESH_H
