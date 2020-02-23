#!/bin/sh

g++ src/*.cpp -o oglhw -lglfw -lGLEW -lGLU -lGL
./oglhw
