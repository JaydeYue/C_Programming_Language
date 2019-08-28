/*  Exercise 1-19
    Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
*/
#include <stdio.h>
#include <string.h>
#include "main.h"

void inputs_reverse() {
    int len, i;
    char line[MAXLINE], reversed[MAXLINE];
    while ((len = book_getline(line, MAXLINE)) > 0) {
        putchar('\n');
        for (i = 0; i < reverse(line, reversed) - 1; i++) 
            putchar(reversed[i]);
    }
}

//  Reverse the original string minus the newline character, return the length of the reversed string
int reverse(char original[], char reversed[]) {
    int i, j;
    for (i = strlen(original) - 1; original[i] == '\n' || original[i] == '\0'; i --);
    for (j = 0; i >= 0; i--, j++) {
        reversed[j] = original[i];
    }
    reversed[j] = '\0';
    j++;
    return j;
}
