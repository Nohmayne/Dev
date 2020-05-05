# Basics Notes

## Things required
> This is for the OpenGL 3.3.0 Core Profile

1. Vertex Array Object
2. Vertex Buffer Object
3. Element Buffer Object
4. Shader Program

## Creation

### General Guide for buffers
```c++
unsigned int bufferName;
glGenBuffers(1, &bufferName);
glBindBuffer(GL_BUFFER_TYPE, bufferName);
glBufferdata(GL_BUFFER_TYPE, sizeof(array), array, GL_DRAW_TYPE);
```

### Steps for a triangle

#### Initialization
1. Bind VAO
2. Copy the vertices array to a VBO
    + Bind and set buffer data
3. Set vertex attributes
    + Set attribute pointers and enable the array
    + Stored in the VAO

#### Rendering
1. Use a shader program
2. Bind the correct VAO
3. Draw call

### Steps for more than one triangle

#### Initialization
1. Bind VAO
2. Copy the vertices array to a VBO
    + Bind and set buffer data
3. Copy the index array to an EBO
    + Bind and set buffer data
4. Set vertex attributes
    + Set attribute pointers and enable the array
    + Stored in the VAO

#### Rendering
1. Use a shader program
2. Bind the correct VAO
3. Draw call
    + Uses DrawElements
4. Unbind the VAO

## Fun things
#### Wireframe mode
```c++
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
```
