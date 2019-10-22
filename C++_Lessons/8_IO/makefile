CC = g++

CFLAGS = -ansi -pedantic -Wall -g

SRCS = IOMain.cpp VirtIO_t.cpp AsciiIO_t.cpp

OBJS = $(SRCS:.c=.o)

MAIN = prog

all: $(MAIN)
	@echo  Program named ‘prog’ has been compiled

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

