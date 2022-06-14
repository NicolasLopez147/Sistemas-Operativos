all: ejecutarMain

compilarMain: main.c
	gcc main.c -o main -pthread

ejecutarMain: compilarMain main
	./main