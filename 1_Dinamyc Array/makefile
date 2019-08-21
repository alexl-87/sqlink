CFLAGS  = -ansi -pedantic -g 

aprog : H_DARRAY.o DARRAYTEST.o
	gcc -o darray H_DARRAY.o DARRAYTEST.o

H_DARRAY.o : H_DARRAY.c H_DARRAY.h
	gcc -c $(CFLAGS) H_DARRAY.c

DARRAYTEST.o : DARRAYTEST.c H_DARRAY.h
	gcc -c $(CFLAGS) DARRAYTEST.c
