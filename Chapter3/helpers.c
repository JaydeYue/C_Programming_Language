#include <stdio.h>
#include "main.h"

//  Recover stdin from EOF while avoiding puting a \0 at the front of the line
void recover_stdin(int exercise) {
    int temp;
    if ((temp = getchar()) == EOF) {
        ungetc('\0', stdin);
        getchar();
    } else {
        printf("Error handling EOF on exercise 3-%d\n", exercise);
    }
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