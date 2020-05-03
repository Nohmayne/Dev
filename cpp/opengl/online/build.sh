#!/bin/sh

g++ -o main src/*.cpp -lglfw -lGLEW -lGLU -lGL && gdb main
