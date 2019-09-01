/*  Exercise 2-2
    Write a loop equivalent to the for loop above without using && or ¦¦.
*/
#include <stdio.h>
#include "main.h"

void for_loop_equivalent() {
    int len;    
    char line[MAXLINE];
    while ((len = no_for_loop_getline(line, MAXLINE)) > 0) {
        printf("Line read: %s", line);
    }
}

int no_for_loop_getline(char s[], int lim) {
    int c, i;
    i = 0;
    while (i<lim-1) {
        if ((c=getchar()) != '\n') {
            if (c != EOF) {
                s[i] = c;
            } else {
                break;
            }
        } else {
            break;
        }
        i++;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}