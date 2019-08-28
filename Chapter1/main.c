/*  Exercises from Chapter 1 of K&R2 i.e. The C Programming Language 2nd Edition book */
#include <stdio.h>
#include "main.h"

int main() {
    printf("------------------------ Exercise 1-1 ------------------------\n");
    hello_world();
    printf("--------------------- End of Exercise 1-1 --------------------\n\n");
    
    //  Commented out by default since this exercise results in warnings at complie time
    //  If you want to include this, uncoment here and uncomment in main.h and add print_invalids.c to Makefile
    // printf("------------------------ Exercise 1-2 ------------------------\n");
    // print_invalids();
    // printf("--------------------- End of Exercise 1-2 ---------------------\n\n");
    
    printf("------------------------ Exercise 1-3 ------------------------\n");
    f_to_c_table();
    printf("--------------------- End of Exercise 1-3 --------------------\n\n");
    
    printf("------------------------ Exercise 1-4 ------------------------\n");
    c_to_f_table();
    printf("--------------------- End of Exercise 1-4 --------------------\n\n");
    
    printf("------------------------ Exercise 1-5 ------------------------\n");
    f_to_c_reverse();
    printf("--------------------- End of Exercise 1-5 --------------------\n\n");
    
    printf("------------------------ Exercise 1-6 ------------------------\n");
    printf("You need to enter EOF to exit the input stream\n");
    verify_expression();
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("--------------------- End of Exercise 1-6 --------------------\n\n");
    
    printf("------------------------ Exercise 1-7 ------------------------\n");
    print_EOF();
    printf("--------------------- End of Exercise 1-7 --------------------\n\n");
    
    printf("------------------------ Exercise 1-8 ------------------------\n");
    printf("This program will count the number of blanks, tabs, and newlines in your input\n");
    printf("You need to enter EOF to exit the input stream\n");
    count_special_char();
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("--------------------- End of Exercise 1-8 --------------------\n\n");
    
    printf("--------------------- Exercise 1-9 & 1-10 --------------------\n");
    printf("This program will shorten continuous blanks and replace some special characters with their string representation\n");
    printf("You need to enter EOF to exit the input stream\n");
    special_char_replace();
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("----------------- End of Exercise 1-9 & 1-10 -----------------\n\n");
    
    printf("----------------------- Exercise 1-11 ------------------------\n");
    printf("Some corner cases input to test for:\n");
    printf("No words and only a variation of blanks, tabs, and newlines\n");
    printf("Empty input\n");
    printf("An input with very large words as well as words with only one letter\n");
    printf("Words separated by combination of blanks, tabs, and newlines\n");
    printf("Words with special characters\n");
    printf("-------------------- End of Exercise 1-11 --------------------\n\n");
    
    printf("----------------------- Exercise 1-12 ------------------------\n");
    printf("This program will print your input one word per line\n");
    printf("You need to enter EOF to exit the input stream\n");
    one_word_per_line();
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("-------------------- End of Exercise 1-12 --------------------\n\n");
    
    printf("----------------------- Exercise 1-13 ------------------------\n");
    printf("This program will print a histogram of word lengths, words longer than 50 characters won't be recorded\n");
    printf("You need to enter EOF to exit the input stream\n");
    //  You can change to HORIZONTAL here
    word_length_histogram(VERTICAL);
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("-------------------- End of Exercise 1-13 --------------------\n\n");
    
    printf("----------------------- Exercise 1-14 ------------------------\n");
    printf("This program will print a histogram of frequencies of characters in your input\n");
    printf("You need to enter EOF to exit the input stream\n");
    //  You can change to HORIZONTAL here
    char_freq_histogram(VERTICAL);
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("-------------------- End of Exercise 1-14 --------------------\n\n");

    printf("----------------------- Exercise 1-15 ------------------------\n");
    f_to_c_with_func();
    printf("-------------------- End of Exercise 1-15 --------------------\n\n");

    printf("----------------------- Exercise 1-16 ------------------------\n");
    printf("This program will print the length of the longest line of input and as much of the text as possible\n");
    printf("You need to enter EOF to exit the input stream\n");
    longest_line_no_limit();
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("-------------------- End of Exercise 1-16 --------------------\n\n");

    printf("----------------------- Exercise 1-17 ------------------------\n");
    int length = 80;
    printf("This program will print all inputs longer than %d characters (only the first %d characters of each line will be printed)\n", length, MAXLINE-1);
    printf("You need to enter EOF to exit the input stream\n");
    inputs_longer_than(length);
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("-------------------- End of Exercise 1-17 --------------------\n\n");

    printf("----------------------- Exercise 1-18 ------------------------\n");
    printf("This program will remove all trailing tabs and blanks and entirely blank lines\n");
    printf("You need to enter EOF to exit the input stream\n");
    rm_trailing();
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("-------------------- End of Exercise 1-18 --------------------\n\n");

    printf("----------------------- Exercise 1-19 ------------------------\n");
    printf("This program will reverse all inputs a line (maximum %d characters) at a time\n", MAXLINE-1);
    printf("You need to enter EOF to exit the input stream\n");
    inputs_reverse();
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("-------------------- End of Exercise 1-19 --------------------\n\n");

    printf("----------------------- Exercise 1-20 ------------------------\n");
    printf("This program will replace tabs with %d number of blanks\n", TABLENGTH);
    printf("You need to enter EOF to exit the input stream\n");
    detab(TABLENGTH);
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("-------------------- End of Exercise 1-20 --------------------\n\n");

    printf("----------------------- Exercise 1-21 ------------------------\n");
    printf("This program will replace strings of blanks with minimum number of tabs and spaces to achieve the same spacing (tablength is %d)\n", TABLENGTH);
    printf("You need to enter EOF to exit the input stream\n");
    entab(TABLENGTH);
    ungetc('\0', stdin);        //  Recover stdin from EOF
    printf("-------------------- End of Exercise 1-21 --------------------\n\n");

    // printf("----------------------- Exercise 1-22 ------------------------\n");
    // printf("This program will fold long input lines at column %d\n", COLUMN_TO_WRAP);
    // printf("You need to enter EOF to exit the input stream\n");
    // fold(COLUMN_TO_WRAP);
    // ungetc('\0', stdin);        //  Recover stdin from EOF
    // printf("-------------------- End of Exercise 1-22 --------------------\n\n");
    return 0;
}
