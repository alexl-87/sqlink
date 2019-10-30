CC = gcc

CFLAGS = -ansi -pedantic -Wall -g

SRCS = DirWalk.c lsmain.c

OBJS = $(SRCS:.c=.o)

MAIN = lsl

all: $(MAIN)
	@echo  Program named 'lsl' has been compiled

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

