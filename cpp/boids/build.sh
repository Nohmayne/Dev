#!/bin/sh

g++ src/*.cpp -o boids -lsfml-graphics -lsfml-window -lsfml-system
./boids
