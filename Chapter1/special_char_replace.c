/*  Exercise 1-9
    Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank

    Exercise 1-10
    Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
*/
#include <stdio.h>

void special_char_replace() {
    int temp, count_blank = 0;
    while ((temp = getchar()) != EOF) {
        switch (temp) {
            case '\b':
                putchar('\\');
                putchar('b');
                count_blank = 0;
                break;
            case '\t':
                putchar('\\');
                putchar('t');
                count_blank = 0;
                break;
            case '\\':
                putchar('\\');
                putchar('\\');
                count_blank = 0;
                break;
            case ' ':
                if (count_blank == 0) {
                    putchar(' ');
                }
                count_blank++;
                break;
            default:
                putchar(temp);
                count_blank = 0;
                break;
        }
    }
}
