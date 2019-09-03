/*  Exercise 1-22
    Write a program to “fold” long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
*/
#include <stdio.h>
#include "main.h"

void fold(int column_to_wrap) {
    int len, i, j, adjusted_wrap = column_to_wrap;
    char line[column_to_wrap+2];
    len = book_getline(line, column_to_wrap+2);
    while (len > 0) {
        if (len <= adjusted_wrap) {
            putline(line, adjusted_wrap);
            adjusted_wrap = column_to_wrap;
        } else if (line[adjusted_wrap] == '\n' || line[adjusted_wrap] == '\t' || line[adjusted_wrap] == ' ') {
            putline(line, adjusted_wrap);
            putchar('\n');
            adjusted_wrap = column_to_wrap;
        } else {
            for (i = len-1; i>=0 && line[i] != ' ' && line[i] != '\t'; i--);
            if (i < 0) {
                putline(line, adjusted_wrap-1);
                putchar('-');
                putchar('\n');
                putchar('-');
                putchar(line[adjusted_wrap-1]);
                putchar(line[adjusted_wrap]);
                adjusted_wrap = column_to_wrap-3;
            } else {
                putline(line, i);
                putchar('\n');
                for (j = i+1; j < len; j++)
                    putchar(line[j]);
                adjusted_wrap = column_to_wrap-(len-i-1);
            }
        }
        len = book_getline(line, adjusted_wrap+2);
    }
}

//  Putchar of line up to limit
void putline(char line[], int limit) {
    int i;
    for (i = 0; i < limit && line[i] != '\0'; i++)
        putchar(line[i]);
}