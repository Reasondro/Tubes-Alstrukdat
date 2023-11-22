#!/bin/bash
SOURCE_FILES=$(find ../ -name "*.c")
gcc -o main.exe $SOURCE_FILES
./main.exe