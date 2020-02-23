#!/bin/sh

g++ src/*.cpp -o tprint -lsfml-graphics -lsfml-window -lsfml-system
./tprint
