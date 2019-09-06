#  the compiler: gcc for C program
CC = gcc

#  compiler flags:
#    -g    adds debugging information to the executable file
#    -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file (in this case the default target entry)
default: chapter3

chapter3: main.c helpers.c  time_binsearch.c escapes.c
	$(CC) $(CFLAGS) -o chapter3.o main.c helpers.c time_binsearch.c escapes.c

clean:
	$(RM) chapter3.o *.o *~
