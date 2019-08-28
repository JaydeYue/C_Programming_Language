/*  Exercise 1-16
    Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.

    book_getline and book_copy are from the book.
*/
#include <stdio.h>
#include "main.h"

void longest_line_no_limit() {
    int len, buffer_len;    
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char buffer[MAXLINE];
    char longest[MAXLINE];  /* longest line saved here */
    max = 0;
    while ((len = book_getline(line, MAXLINE)) > 0) {
        //  While the last real character isn't new line, continue get lines until the end of line is reached
        buffer_len = len;
        book_copy(buffer, line);
        while (buffer_len > 0 && buffer[buffer_len-1] != '\n') {
            buffer_len = book_getline(buffer, MAXLINE);
            len += buffer_len;
        }
        if (len > max) {
            max = len;
            book_copy(longest, line);
        }
    }
    printf("Longest line has %d characters\n", max);
    if (max > 0) {
        if (max > MAXLINE-1) {
            max = MAXLINE -1;
        }
        if (longest[max-1] == '\n') {
            printf("First %d characters of longest line: %.*s%s\n", MAXLINE-1, max-1, longest, "\\n");
        } else {
            printf("First %d characters of longest line: %s\n", MAXLINE-1, longest);
        }
    }
}

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
