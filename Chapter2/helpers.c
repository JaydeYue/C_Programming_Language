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