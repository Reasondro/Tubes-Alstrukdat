#!/bin/bash
C_SOURCE_FILES=$(find ../ -name "*.c")
gcc -o main.exe $C_SOURCE_FILES
./main.exe
