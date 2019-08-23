#  the compiler: gcc for C program
CC = gcc

#  compiler flags:
#    -g    adds debugging information to the executable file
#    -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file (in this case the default target entry)
default: chapter1

chapter1: main.c hello_world.c
	$(CC) $(CFLAGS) -o chapter1 main.c hello_world.c

clean:
	$(RM) chapter1 *.o *~
