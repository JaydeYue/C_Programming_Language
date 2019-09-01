/* Exercises from Chapter 2 of K&R2 i.e. The C Programming Language 2nd Edition book */
#include <stdio.h>
#include "main.h"

int main() {
    char EOF_statement[] = "You need to enter EOF to exit the input stream\n";
    char line[MAXLINE];
    char s1[MAXLINE];
    char s2[MAXLINE];
    int line_len;

    // printf("------------------------ Exercise 2-1 ------------------------\n");
    // determine_range();
    // printf("--------------------- End of Exercise 2-1 --------------------\n\n");

    printf("------------------------ Exercise 2-2 ------------------------\n");
    printf("This program implements book_getline in chapter1 without using and/or operators\n%s", EOF_statement);
    for_loop_equivalent();
    // if (getchar() == EOF)
        ungetc('\0', stdin);
    printf("--------------------- End of Exercise 2-2 --------------------\n\n");

    printf("------------------------ Exercise 2-3 ------------------------\n");
    printf("This program converts your inputted integer hex number (started with or without 0x/0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.\n%s", EOF_statement);
    htoi();
    // if (getchar() == EOF)
        ungetc('\0', stdin);
    printf("--------------------- End of Exercise 2-3 --------------------\n\n");

    printf("------------------------ Exercise 2-4 ------------------------\n");
    printf("This program will delete each character in s1 that matches any character in s2\n%s", EOF_statement);
    while ((line_len = get_from_input(" \t\n", line, MAXLINE)) == 0);
    book_copy(s1, line);
    while ((line_len = get_from_input(" \t\n", line, MAXLINE)) == 0);
    book_copy(s2, line);
    squeeze(s1, s2);
    // if (getchar() == EOF)
        ungetc('\0', stdin);
    printf("s1 after deletions: %s\n", s1);
    printf("--------------------- End of Exercise 2-4 --------------------\n\n");

    printf("------------------------ Exercise 2-5 ------------------------\n");
    printf("This program returns the first location (starting 0) in s1 where any char from s2 occurs, or −1 if there is none\n%s", EOF_statement);
    while ((line_len = get_from_input(" \t\n", line, MAXLINE)) == 0);
    book_copy(s1, line);
    while ((line_len = get_from_input(" \t\n", line, MAXLINE)) == 0);
    book_copy(s2, line);
    printf("Location: %d\n", any(s1, s2));
    // if (getchar() == EOF)
        ungetc('\0', stdin);
    printf("--------------------- End of Exercise 2-5 --------------------\n\n");

    //  FIXME: this getchar EOF issue causes exercises misbehaving
    return 0;
}
