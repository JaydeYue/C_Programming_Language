/*  Exercise 1-20
    Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
*/
#include <stdio.h>
#include "main.h"

void detab(int tablength) {
    int temp, i;
    while ((temp = getchar()) != EOF) {
        switch (temp) {
        case '\t':
            for (i = 0; i < tablength; i++)
                putchar(' ');
            break;
        default:
            putchar(temp);
            break;
        }
    }
}