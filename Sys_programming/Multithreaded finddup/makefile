CFLAGS = -c -ansi -pedantic -g
LFLAGS = -lcrypto -lssl -pthread

fdup : MD5_calculator.o DirWalk.o H_Hash.o FindDuplicate.o strQueue.o
	gcc -o fdup MD5_calculator.o DirWalk.o H_Hash.o FindDuplicate.o strQueue.o $(LFLAGS)

MD5_calculator.o : MD5_calculator.c MD5_calculator.h
	gcc $(CFLAGS) MD5_calculator.c

DirWalk.o : DirWalk.c DirWalk.h
	gcc $(CFLAGS) DirWalk.c

H_Hash.o : H_Hash.c H_Hash.h
	gcc $(CFLAGS) H_Hash.c

FindDup.o : FindDuplicate.c FindDuplicate.h DirWalk.h H_Hash.h MD5_calculator.h
	gcc $(CFLAGS) FindDup.c

strQueue.o : strQueue.c strQueue.h
	gcc $(CFLAGS) strQueue.c
