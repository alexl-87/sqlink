all: prog

prog: list.o Main.o
	gcc -o prog list.o Main.o

list.o: list.c list.h
	gcc -c list.c

Main.o: main.c list.h
	gcc -c Main.c
