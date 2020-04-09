//
// Created by Daniel Baranowski on 09/04/2020.
//

#ifndef OPEN_GL_TUTORIAL_TEXTURE_H
#define OPEN_GL_TUTORIAL_TEXTURE_H

#include <GL/glew.h>
#include "stb_image.h"

class Texture {
public:
    Texture();
    Texture(char* fileLoc);

    void LoadTexture();
    void UseTexture();
    void ClearTexture();

    ~Texture();

private:
    GLuint textureID;
    int width, height, bitDepth;
    char* fileLocation;
};


#endif //OPEN_GL_TUTORIAL_TEXTURE_H
