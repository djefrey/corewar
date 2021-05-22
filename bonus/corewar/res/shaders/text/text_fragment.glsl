#version 330 core

in vec2 UV;

out vec4 color;

uniform sampler2D textureSampler;
uniform vec3 colorFactor;

void main() {
    color = texture(textureSampler, UV) * vec4(colorFactor, 1);
}