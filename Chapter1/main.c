/*  Exercises from Chapter 1 of K&R2 i.e. The C Programming Language 2nd Edition book */
#include <stdio.h>
#include "main.h"

int main() {
    printf("--------------------- Exercise 1-1 ---------------------\n");
    hello_world();
    printf("------------------ End of Exercise 1-1 -----------------\n\n");

    //  Commented out by default since this exercise results in warnings at complie time
    //  If you want to include this, uncoment here and uncomment in main.h and add print_invalids.c to Makefile
    // printf("--------------------- Exercise 1-2 ---------------------\n");
    // print_invalids();
    // printf("------------------ End of Exercise 1-2 ------------------\n\n");

    printf("--------------------- Exercise 1-3 ---------------------\n");
    f_to_c_table();
    printf("------------------ End of Exercise 1-3 -----------------\n\n");

    printf("--------------------- Exercise 1-4 ---------------------\n");
    c_to_f_table();
    printf("------------------ End of Exercise 1-4 -----------------\n\n");

    printf("--------------------- Exercise 1-5 ---------------------\n");
    f_to_c_reverse();
    printf("------------------ End of Exercise 1-5 -----------------\n\n");

    printf("--------------------- Exercise 1-6 ---------------------\n");
    printf("EOF is ctrl+D on mac and ctrl+Z on windows; You need to enter EOF to exit the input stream\n");
    verify_expression();
    //  Recover stdin from EOF
    ungetc('\0', stdin);
    printf("------------------ End of Exercise 1-6 -----------------\n\n");

    printf("--------------------- Exercise 1-7 ---------------------\n");
    print_EOF();
    printf("------------------ End of Exercise 1-7 -----------------\n\n");

    printf("--------------------- Exercise 1-8 ---------------------\n");
    printf("This program will count the number of blanks, tabs, and newlines in your input\n");
    printf("EOF is ctrl+D on mac and ctrl+Z on windows; You need to enter EOF to exit the input stream\n");
    count_special_char();
    //  Recover stdin from EOF
    ungetc('\0', stdin);
    printf("------------------ End of Exercise 1-8 -----------------\n\n");

    printf("------------------ Exercise 1-9 & 1-10 -----------------\n");
    printf("This program will shorten continuous blanks and replace some special characters with their string representation\n");
    printf("EOF is ctrl+D on mac and ctrl+Z on windows; You need to enter EOF to exit the input stream\n");
    special_char_replace();
    //  Recover stdin from EOF
    ungetc('\0', stdin);
    printf("-------------- End of Exercise 1-9 & 1-10 --------------\n\n");

    printf("-------------------- Exercise 1-11 ---------------------\n");
    printf("Some corner cases input to test for:\n");
    printf("No words and only a variation of blanks, tabs, and newlines\n");
    printf("Empty input\n");
    printf("An input with very large words as well as words with only one letter\n");
    printf("Words separated by combination of blanks, tabs, and newlines\n");
    printf("Words with special characters\n");
    printf("----------------- End of Exercise 1-11 -----------------\n\n");

    printf("-------------------- Exercise 1-12 ---------------------\n");
    printf("This program will print your input one word per line\n");
    printf("EOF is ctrl+D on mac and ctrl+Z on windows; You need to enter EOF to exit the input stream\n");
    one_word_per_line();
    //  Recover stdin from EOF
    ungetc('\0', stdin);
    printf("----------------- End of Exercise 1-12 -----------------\n\n");

    printf("-------------------- Exercise 1-13 ---------------------\n");
    printf("This program will print a histogram of word lengths, words longer than 50 characters won't be recorded\n");
    printf("EOF is ctrl+D on mac and ctrl+Z on windows; You need to enter EOF to exit the input stream\n");
    //  You can change to HORIZONTAL here
    word_length_histogram(VERTICAL);
    //  Recover stdin from EOF
    ungetc('\0', stdin);
    printf("----------------- End of Exercise 1-13 -----------------\n\n");
    return 0;
}
