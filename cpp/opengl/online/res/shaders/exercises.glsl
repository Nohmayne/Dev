#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
out vec3 newPosition;

uniform float xOffset;

void main()
{
    gl_Position = vec4(aPos.x + xOffset, -aPos.y, aPos.z, 1.0);
    newPosition = gl_Position.xyz;
}

#shader fragment
#version 330 core
in vec3 newPosition;
out vec4 FragColor;

void main()
{
    FragColor = vec4(newPosition, 1.0);
}
