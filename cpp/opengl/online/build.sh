#!/bin/sh

g++ -o main src/*.cc -lglfw -lGLEW -lGLU -lGL && gdb main
