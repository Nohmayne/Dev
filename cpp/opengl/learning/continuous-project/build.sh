#!/bin/sh

g++ src/*.cpp -o vbs -lglfw -lGLEW -lGLU -lGL
./vbs
