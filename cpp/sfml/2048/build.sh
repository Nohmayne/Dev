#!/bin/sh

g++ -o 2048 src/*.cpp include/*.h -lsfml-graphics -lsfml-window -lsfml-system
./2048
