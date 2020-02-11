#!/bin/sh

g++ src/*.cpp include/*.h -o 2048 -lsfml-graphics -lsfml-window -lsfml-system
./2048