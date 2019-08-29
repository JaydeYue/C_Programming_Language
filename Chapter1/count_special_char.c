/*  Exercise 1-8
    Write a program to count blanks, tabs, and newlines.
*/
#include <stdio.h>

void count_special_char() {
    int temp;
    int blank, tab, newline, other;
    blank = tab = newline = other = 0;
    while ((temp = getchar()) != EOF) {
        switch (temp) {
        case '\n':
            newline++;
            break;
        case '\t':
            tab++;
            break;
        case ' ':
            blank++;
            break;
        case '\0':
            break;
        default:
            other++;
            break;
        }
    }
    printf("# of blanks: %d;  # of tabs: %d; # of newlines: %d; # of other char: %d\n", blank, tab, newline, other);
}
