/*  Exercise 1-18
    Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
*/
#include <stdio.h>
#include "main.h"

void rm_trailing() {
    int temp, i, count_blank = 0, count_tab = 0, count_char = 0;
    while ((temp = getchar()) != EOF) {
        switch (temp) {
        case '\t':
            count_tab++;
            break;
        case ' ':
            count_blank++;
            break;
        case '\n':
            count_tab = count_blank = count_char = 0;
            break;
        default:
            if (count_char == 0) {
                putchar('\n');
            }
            for (i = 0; i < count_tab; i++)
                putchar('\t');
            for (i = 0; i < count_blank; i++)
                putchar(' ');
            count_tab = count_blank = 0;
            putchar(temp);
            count_char++;
            break;
        }
    }
}
