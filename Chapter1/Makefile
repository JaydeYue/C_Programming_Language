#  the compiler: gcc for C program
CC = gcc

#  compiler flags:
#    -g    adds debugging information to the executable file
#    -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file (in this case the default target entry)
default: chapter1

chapter1: main.c hello_world.c f_to_c_table.c c_to_f_table.c f_to_c_reverse.c verify_expression.c print_EOF.c count_special_char.c special_char_replace.c one_word_per_line.c word_length_histogram.c char_freq_histogram.c
	$(CC) $(CFLAGS) -o chapter1.o main.c hello_world.c f_to_c_table.c c_to_f_table.c f_to_c_reverse.c verify_expression.c print_EOF.c count_special_char.c special_char_replace.c one_word_per_line.c word_length_histogram.c char_freq_histogram.c

clean:
	$(RM) chapter1.o *.o *~
