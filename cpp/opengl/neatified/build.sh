#!/bin/sh

clear

g++ -o main src/*.cc -lglfw -lGLEW -lGLU -lGL && gdb main

# echo "Press any key to continue..."
# while [ true ] ; do
#     read -t 3 -n 1
#     if [ $? = 0 ] ; then
# 	exit ;
#     fi
# done
