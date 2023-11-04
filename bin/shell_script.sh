#!/bin/bash

echo "Shell Script Runningg...."

# Get the list of all C source code files in the repo
C_SOURCE_FILES=$(find ../ -name "*.c")

# echo $C_SOURCE_FILES

# Compile all sources
gcc -o main.exe $C_SOURCE_FILES

echo "Compiling finished..."
echo "Starting main.exe..."
echo " "

# Run exe
./main.exe
