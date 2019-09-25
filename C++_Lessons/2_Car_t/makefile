CC = g++

CFLAGS = -ansi -pedantic -Wall -g

SRCS = Car_t.cpp CarMain.cpp

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

