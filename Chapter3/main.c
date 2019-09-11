/* Exercises from Chapter 3 of K&R2 i.e. The C Programming Language 2nd Edition book */
#include <stdio.h>
#include "main.h"

int main() {
    char EOF_statement[] = "You need to enter EOF to exit the input stream: ctrl+z on win, ctr+d on unix\n";
    char line[MAXLINE], s1[MAXLINE], s2[MAXLINE];
    int line_len;

    printf("------------------------ Exercise 3-1 ------------------------\n");
    printf("This program will time two different binary search functions on a randomly generated array with a size of %d\n", MAXLINE);
    time_binsearch();
    printf("--------------------- End of Exercise 3-1 --------------------\n\n");

    printf("------------------------ Exercise 3-2 ------------------------\n");
    printf("This program takes in your input, then convert special characters to their visible escape sequences and back\n%s", EOF_statement);
    printf("Your input: ");
    while ((line_len = get_from_input("", line, MAXLINE)) == 0 && line_len != -1);
    putchar('\n');
    real_to_escape(line, s1);
    printf("To escape sequences: %s\n", s1);
    escape_to_real(s1, s2);
    printf("To real: %s\n", s2);
    if (line_len == -1) {
        recover_stdin(2);
    }
    printf("--------------------- End of Exercise 3-2 --------------------\n\n");

    printf("------------------------ Exercise 3-3 ------------------------\n");
    printf("This program expands shorthand notations like a-z, 0-9, Z-A in your input into the equivalent complete list abc...xyz\n%s", EOF_statement);
    printf("Your input: ");
    while ((line_len = get_from_input("", line, MAXLINE)) == 0 && line_len != -1);
    putchar('\n');
    expand(line, s1);
    printf("After expansion: %s\n", s1);
    if (line_len == -1) {
        recover_stdin(3);
    }
    printf("--------------------- End of Exercise 3-3 --------------------\n\n");

    return 0;
}