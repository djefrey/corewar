#version 330 core

layout(location = 0) in vec4 coords;

out vec2 UV;

void main() {
    vec2 vertexPos_homoneneousspace = coords.xy - vec2(400,300); // [0..800][0..600] -> [-400..400][-300..300]
    vertexPos_homoneneousspace /= vec2(400,300);

    gl_Position = vec4(vertexPos_homoneneousspace, 0, 1);
    UV = coords.zw;
}