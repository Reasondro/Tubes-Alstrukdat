@echo off
Title "WayangWave"
echo Memuat file...
gcc ../src/main.c ../src/console.c ../src/ADT/LinkedList/listlinier.c ../src/ADT/Map/map.c  ../src/ADT/MesinKarakter_MesinKata/mesinkarakter.c ../src/ADT/MesinKarakter_MesinKata/mesinkata.c ../src/ADT/Queue/queue.c ../src/ADT/Setmap-TEMPORER/SETMAP.c ../src/ADT/stack/stack.c -o WayangWave.exe
WayangWave.exe