#!/bin/sh

g++ ../src/*.cpp -o vbsOSX -I"/usr/local/Cellar/glfw/3.3.2/include" -L"/usr/local/Cellar/glfw/3.3.2/lib" -lglfw -I"/usr/local/Cellar/glew/2.1.0_1/include" -L"/usr/local/Cellar/glew/2.1.0_1/lib" -lGLEW
