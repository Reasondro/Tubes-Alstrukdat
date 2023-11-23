all: run clean

run:
	gcc ../src/main.c ../src/ADT/Stack/stack.c ../src/ADT/List/list.c ../src/ADT/LinkedList/listlinier.c ../src/ADT/MesinKarakter_MesinKata/mesinkarakter.c ../src/ADT/MesinKarakter_MesinKata/mesinkata.c ../src/ADT/Queue/queue.c ../src/ADT/Setmap-TEMPORER/SETMAP.c ../src/console.c -o WayangWave.exe
	./WayangWave.exe

clean:
	del WayangWave.exe