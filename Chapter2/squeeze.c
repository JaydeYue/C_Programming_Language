/*  Exercise 2-4
    Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.
*/
#include <stdio.h>
#include "main.h"

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int if_delete = FALSE;
    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                if_delete = TRUE;
                break;
            }
        }
        if (!if_delete) {
            s1[k++] = s1[i];
        } else {
            if_delete = FALSE;
        }
    }
     s1[k] = '\0';
}