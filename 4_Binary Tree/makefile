CFLAGS = -ansi -pedantic -g

aprog : H_BST.o BSTTest.o
	gcc -o BST H_BST.o BSTTest.o

H_BST.o : H_BST.c H_BST.h
	gcc -c $(CFLAGS) H_BST.c

BSTTest.o : BSTTest.c H_BST.h
	gcc -c $(CFLAGS) BSTTest.c
