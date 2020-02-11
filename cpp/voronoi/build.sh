#!/bin/sh

g++ src/*.cpp -o voronoi -lsfml-graphics -lsfml-window -lsfml-system
./voronoi