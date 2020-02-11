#!/bin/sh

# Compile all .cpp files in src folder using sfml args
g++ src/*.cpp -o web -lsfml-graphics -lsfml-window -lsfml-system