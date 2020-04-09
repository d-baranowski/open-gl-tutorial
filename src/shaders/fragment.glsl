#version 330

in vec4 vColor;
in vec2 texCord;
out vec4 color;

uniform sampler2D theTexture;

void main()
{
    color = texture(theTexture, texCord) * vColor;
}
