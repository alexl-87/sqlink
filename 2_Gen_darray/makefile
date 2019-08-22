CFLAGS = -ansi -pedantic -g

aprog: darray_generic.o dArrayTest.o
	gcc -o dArrayEXE darray_generic.o dArrayTest.o

darray_generic.o : darray_generic.c darray_generic.h
	gcc -c $(CFLAGS) darray_generic.c

dArrayTest.o : dArrayTest.c darray_generic.h
	gcc -c $(CFLAGS) dArrayTest.c 


