#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
// layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

// out vec3 mColor;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    // mColor = aColor;
    TexCoord = aTexCoord;
}

#shader fragment
#version 330 core
out vec4 FragColor;

// in vec3 mColor;
in vec2 TexCoord;

uniform sampler2D mTexture1; 
uniform sampler2D mTexture2; 

void main()
{
    FragColor = mix(texture(mTexture1, TexCoord), texture(mTexture2, 2.0 * TexCoord), 0.8);
}
