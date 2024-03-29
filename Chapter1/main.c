/*  Exercises from Chapter 1 of K&R2 i.e. The C Programming Language 2nd Edition book */
#include <stdio.h>
#include "main.h"

int main() {
    char EOF_statement[] = "You need to enter EOF to exit the input stream: ctrl+z on win, ctr+d on unix\n";

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
    printf("This program will print out the value of the expression: getchar() != EOF\n%s", EOF_statement);
    verify_expression();
    recover_stdin(6);
    printf("--------------------- End of Exercise 1-6 --------------------\n\n");
    
    printf("------------------------ Exercise 1-7 ------------------------\n");
    print_EOF();
    printf("--------------------- End of Exercise 1-7 --------------------\n\n");
    
    printf("------------------------ Exercise 1-8 ------------------------\n");
    printf("This program will count the number of blanks, tabs, and newlines in your input\n%s", EOF_statement);
    count_special_char();
    recover_stdin(8);
    printf("--------------------- End of Exercise 1-8 --------------------\n\n");
    
    printf("--------------------- Exercise 1-9 & 1-10 --------------------\n");
    printf("This program will shorten continuous blanks and replace some special characters with their string representation\n%s", EOF_statement);
    special_char_replace();
    recover_stdin(9);
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
    printf("This program will print your input one word per line\n%s", EOF_statement);
    one_word_per_line();
    recover_stdin(12);
    printf("-------------------- End of Exercise 1-12 --------------------\n\n");
    
    printf("----------------------- Exercise 1-13 ------------------------\n");
    printf("This program will print a histogram of word lengths, words longer than 50 characters won't be recorded\n%s", EOF_statement);
    //  You can change to HORIZONTAL here
    word_length_histogram(VERTICAL);
    recover_stdin(13);
    printf("-------------------- End of Exercise 1-13 --------------------\n\n");
    
    printf("----------------------- Exercise 1-14 ------------------------\n");
    printf("This program will print a histogram of frequencies of characters in your input\n%s", EOF_statement);
    //  You can change to HORIZONTAL here
    char_freq_histogram(VERTICAL);
    recover_stdin(14);
    printf("-------------------- End of Exercise 1-14 --------------------\n\n");

    printf("----------------------- Exercise 1-15 ------------------------\n");
    f_to_c_with_func();
    printf("-------------------- End of Exercise 1-15 --------------------\n\n");

    printf("----------------------- Exercise 1-16 ------------------------\n");
    printf("This program will print the length of the longest line of input and as much of the text as possible\n%s", EOF_statement);
    longest_line_no_limit();
    recover_stdin(16);
    printf("-------------------- End of Exercise 1-16 --------------------\n\n");

    printf("----------------------- Exercise 1-17 ------------------------\n");
    int length = 80;
    printf("This program will print all inputs longer than %d characters (only the first %d characters of each line will be printed)\n%s", length, MAXLINE-1, EOF_statement);
    inputs_longer_than(length);
    recover_stdin(17);
    printf("-------------------- End of Exercise 1-17 --------------------\n\n");

    printf("----------------------- Exercise 1-18 ------------------------\n");
    printf("This program will remove all trailing tabs and blanks and entirely blank lines\n%s", EOF_statement);
    rm_trailing();
    recover_stdin(18);
    printf("-------------------- End of Exercise 1-18 --------------------\n\n");

    printf("----------------------- Exercise 1-19 ------------------------\n");
    printf("This program will reverse all inputs a line (maximum %d characters) at a time\n%s", MAXLINE-1, EOF_statement);
    inputs_reverse();
    recover_stdin(19);
    printf("-------------------- End of Exercise 1-19 --------------------\n\n");

    printf("----------------------- Exercise 1-20 ------------------------\n");
    printf("This program will replace tabs with %d number of blanks\n%s", TABLENGTH, EOF_statement);
    detab(TABLENGTH);
    recover_stdin(20);
    printf("-------------------- End of Exercise 1-20 --------------------\n\n");

    printf("----------------------- Exercise 1-21 ------------------------\n");
    printf("This program will replace strings of blanks with minimum number of tabs and spaces to achieve the same spacing (tablength is %d)\n%s", TABLENGTH, EOF_statement);
    entab(TABLENGTH);
    recover_stdin(21);
    printf("-------------------- End of Exercise 1-21 --------------------\n\n");

    printf("----------------------- Exercise 1-22 ------------------------\n");
    printf("This program will fold long input lines at column %d\n%s", COLUMN_TO_WRAP, EOF_statement);
    fold(COLUMN_TO_WRAP);
    recover_stdin(22);
    printf("-------------------- End of Exercise 1-22 --------------------\n\n");

    printf("----------------------- Exercise 1-23 ------------------------\n");
    printf("This program will remove all comments of the inputted c program\n%s", EOF_statement);
    rm_c_comments();
    recover_stdin(23);
    printf("-------------------- End of Exercise 1-23 --------------------\n\n");

    printf("----------------------- Exercise 1-24 ------------------------\n");
    printf("This program will check for basic syntax of one inputted c program\n%s", EOF_statement);
    syntax_checker();
    recover_stdin(24);
    printf("-------------------- End of Exercise 1-24 --------------------\n\n");
    return 0;
}

//  Recover stdin from EOF while avoiding puting a \0 at the front of the line
void recover_stdin(int exercise) {
    int temp;
    if ((temp = getchar()) == EOF) {
        ungetc('\0', stdin);
        getchar();
    } else {
        printf("Error handling EOF on exercise 2-%d\n", exercise);
    }
}
