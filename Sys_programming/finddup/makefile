fdup : MD5_calculator.o DirWalk.o H_Hash.o FindDuplicate.o
	gcc -o fdup MD5_calculator.o DirWalk.o H_Hash.o FindDuplicate.o -lcrypto -lssl

MD5_calculator.o : MD5_calculator.c MD5_calculator.h
	gcc -c -ansi -pedantic MD5_calculator.c

DirWalk.o : DirWalk.c DirWalk.h
	gcc -c -ansi -pedantic DirWalk.c

H_Hash.o : H_Hash.c H_Hash.h
	gcc -c -ansi -pedantic H_Hash.c

FindDup.o : FindDuplicate.c FindDuplicate.h DirWalk.h H_Hash.h MD5_calculator.h
	gcc -c -ansi -pedantic FindDup.c
