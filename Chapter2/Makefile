#  the compiler: gcc for C program
CC = gcc

#  compiler flags:
#    -g    adds debugging information to the executable file
#    -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file (in this case the default target entry)
default: chapter2

chapter2: main.c helpers.c determine_range.c for_loop_equivalent.c htoi.c squeeze.c any.c setbits.c
	$(CC) $(CFLAGS) -o chapter2.o main.c helpers.c determine_range.c for_loop_equivalent.c htoi.c squeeze.c any.c setbits.c

clean:
	$(RM) chapter2.o *.o *~
