CFLAGS = -c -pedantic -Wall -Werror -O2
LFLAGS = -o
EXECUTABLE = file_holes
PATH_TO_FILE = /home/alex/MyGit/sqlink/Demos/file_holes.c

file_holes: file_holes.o
	gcc file_holes.o $(LFLAGS) $(EXECUTABLE)

file_holes.o: file_holes.c
	gcc $(CFLAGS) file_holes.c

.PHONY: clean
clean:
	rm *.o 
	rm $(EXECUTABLE)
ifeq ($(wildcard test_file),test_file)
	rm test_file
else

endif


.PHONY: run
run:
	./$(EXECUTABLE)
