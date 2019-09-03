/* Exercises from Chapter 2 of K&R2 i.e. The C Programming Language 2nd Edition book */
#include <stdio.h>
#include "main.h"

int main() {
    char EOF_statement[] = "You need to enter EOF to exit the input stream: ctrl+z on win, ctr+d on unix\n";
    char line[MAXLINE];
    char s1[MAXLINE];
    char s2[MAXLINE];
    int line_len;

    printf("------------------------ Exercise 2-1 ------------------------\n");
    determine_range();
    printf("--------------------- End of Exercise 2-1 --------------------\n\n");

    printf("------------------------ Exercise 2-2 ------------------------\n");
    printf("This program implements book_getline in chapter1 without using and/or operators\n%s", EOF_statement);
    for_loop_equivalent();
    recover_stdin(2);
    printf("--------------------- End of Exercise 2-2 --------------------\n\n");

    printf("------------------------ Exercise 2-3 ------------------------\n");
    printf("This program converts your inputted integer hex number (started with or without 0x/0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.\n%s", EOF_statement);
    htoi();
    recover_stdin(3);
    printf("--------------------- End of Exercise 2-3 --------------------\n\n");

    printf("------------------------ Exercise 2-4 ------------------------\n");
    printf("This program will delete each character in s1 that matches any character in s2\n");
    while ((line_len = get_from_input(" \t\n", line, MAXLINE)) == 0 && line_len != -1);
    book_copy(s1, line);
    while ((line_len = get_from_input(" \t\n", line, MAXLINE)) == 0 && line_len != -1);
    book_copy(s2, line);
    if (line_len == -1) {
        printf("You have exited prematurely with EOF\n");
        recover_stdin(4);
    } else {
        squeeze(s1, s2);
        printf("s1 after deletions: %s\n", s1);
    }
    printf("--------------------- End of Exercise 2-4 --------------------\n\n");

    printf("------------------------ Exercise 2-5 ------------------------\n");
    printf("This program returns the first location (starting 0) in s1 where any char from s2 occurs, or −1 if there is none\n");
    while ((line_len = get_from_input(" \t\n", line, MAXLINE)) == 0 && line_len != -1);
    book_copy(s1, line);
    while ((line_len = get_from_input(" \t\n", line, MAXLINE)) == 0 && line_len != -1);
    book_copy(s2, line);
    if (line_len == -1) {
        printf("You have exited prematurely with EOF\n");
        recover_stdin(5);
    } else {
        printf("Location: %d\n", any(s1, s2));
    }
    printf("--------------------- End of Exercise 2-5 --------------------\n\n");

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