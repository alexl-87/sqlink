CC = g++

CFLAGS = -ansi -pedantic -Wall -g

SRCS = CalendarMain.cpp Calendar_t.cpp Meeting_t.cpp

OBJS = $(SRCS:.c=.o)

MAIN = Prog

all: $(MAIN)
	@echo  Program named ‘Prog’ has been compiled

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

