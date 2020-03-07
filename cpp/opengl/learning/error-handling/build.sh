#!/bin/sh

g++ -g src/*.cpp -o main -lglfw -lGLEW -lGLU -lGL && gdb main
