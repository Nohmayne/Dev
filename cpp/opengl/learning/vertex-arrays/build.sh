#!/bin/sh

g++ src/*.cpp -o main -lglfw -lGLEW -lGLU -lGL && gdb main
