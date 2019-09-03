#include <stdio.h>
#include "main.h"

/*  From book - book_getline: read a line into s, return length */
int book_getline(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/*  From book - book_copy: book_copy ′from′ into ′to′; assume to is big enough */
void book_copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/*  From book - getbits:  get n bits from position p */
unsigned book_getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

//  Store the input read up to one of the separators into line, lim is max size of line, return the length
int get_from_input(char separators[], char line[], int lim) {
    int c, j, i;
    int if_break = FALSE;
    for (i=0; i<lim-1 && (c=getchar())!=EOF; i++) {
        for (j = 0; separators[j] != '\0'; j++) {
            if (separators[j] == c) {
                if_break = TRUE;
                break;
            }
        }
        if (if_break)
            break;
        line[i] = c;
    }
    if (c == EOF) {
        line[i] = '\0';
        return -1;
    } else {
        line[i] = '\0';
        return i;
    }
}

//  read a positive decimal from a line
int read_decimal_from_line(char line[]) {
    int i = 0, decimal =0;
    while(line[i] != '\0' && line[i] != '\n') {
        if (line[i] <= '9' && line[i] >= '0') {
            decimal = decimal * 10 + line[i] - '0';
            i++;
        } else {
            return -1;
        }
    }
    return decimal;
}

//  print an unsigned number in binary
void print_in_binary(unsigned number) {
    int length = 1;
    unsigned test_length = number, mask;
    while ((test_length /= 2) != 0)
        length++;
    while ((length -= 1) >= 0) {
        mask = 1 << length;
        if (number & mask) {
            putchar('1');
        } else {
            putchar('0');
        }
    }
}