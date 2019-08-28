/*  Exercise 1-17
    Write a program to print all input lines that are longer than 80 characters.
*/
#include <stdio.h>
#include "main.h"

void inputs_longer_than(int length) {
    int len, buffer_len, i;
    char line[MAXLINE];     /* current input line */
    char buffer[MAXLINE];
    char printed[100] = "\nLonger: ";
    while ((len = book_getline(line, MAXLINE)) > 0) {
        //  While the last real character isn't new line, continue get lines until the end of line is reached
        buffer_len = len;
        book_copy(buffer, line);
        while (buffer_len > 0 && buffer[buffer_len-1] != '\n') {
            buffer_len = book_getline(buffer, MAXLINE);
            len += buffer_len;
        }
        if (len > length) {
            for (i = 0; printed[i] != '\0'; i++)
                putchar(printed[i]);
            if (len > MAXLINE-1) {
                len = MAXLINE -1;
            }
            for (i = 0; i < len; i++) {
                if (line[i] != '\n') {
                    putchar(line[i]);
                } else {
                    putchar('\\');
                    putchar('n');
                }
            }
        }
    }
}
