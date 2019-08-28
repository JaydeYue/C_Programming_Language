/*  Exercise 1-22
    Write a program to “fold” long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
*/
#include <stdio.h>
#include "main.h"

void fold(int column_to_wrap) {
    int len, i, j, adjusted_wrap = column_to_wrap;
    char line[column_to_wrap+1];
    len = book_getline(line, column_to_wrap+1);
    while (len > 0) {
        if (len < adjusted_wrap || line[adjusted_wrap-1] == '\n') {
            putline(line, adjusted_wrap);
            len = book_getline(line, column_to_wrap+1);
            printf("AA");
        } else {
            for (i = len-1; i>=0 && line[i] != ' ' && line[i] != '\t'; i--);
            if (i < 0) {
                putline(line, adjusted_wrap-1);
                putchar('-');
                putchar('\n');
                putchar('-');
                putchar(line[adjusted_wrap-1]);
                adjusted_wrap = column_to_wrap-2;
                len = book_getline(line, adjusted_wrap+1);
                printf("BB");
            } else {
                putline(line, i);
                putchar('\n');
                for (j = i+1; j < len; j++)
                    putchar(line[j]);
                adjusted_wrap = i+1;
                len = book_getline(line, adjusted_wrap+1);
                printf("CC");
            }
        }
    }
}

//  Putchar of line up to limit
void putline(char line[], int limit) {
    int i;
    for (i = 0; i < limit; i++)
        putchar(line[i]);
}