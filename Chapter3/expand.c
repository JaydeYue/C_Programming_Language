/*  Exercise 3-3
    Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0−9 and -a-z. Arrange that a leading or trailing - is taken literally.
*/
#include <stdio.h>
#include "main.h"

void expand(char from[], char to[]) {
    int if_dash = FALSE;
    char prev_char, temp;
    for (int i=0, j=0; from[i] != EOF && from[i] != '\0'; i++, j++) {
        if (from[i] == '-' && ((prev_char <= 'Z' && prev_char >= 'A') || (prev_char <= 'z' && prev_char >= 'a') || (prev_char <= '9' && prev_char >= '0'))) {
            if_dash = TRUE;
            j--;
        } else {
            if (if_dash) {
                if ((from[i] <= 'Z' && from[i] >= 'A' && prev_char <= 'Z' && prev_char >= 'A') || (from[i] <= 'z' && from[i] >= 'a' && prev_char <= 'z' && prev_char >= 'a') || (from[i] <= '9' && from[i] >= '0' && prev_char <= '9' && prev_char >= '0')) {
                    if (from[i] >= prev_char) 
                        for (temp = prev_char + 1; (to[j] = temp) < from[i]; temp++, j++);
                    else
                        for (temp = prev_char - 1; (to[j] = temp) > from[i]; temp--, j++);
                } else {
                    to[j++] = '-';
                }
            } 
            if_dash = FALSE;
            to[j] = prev_char = from[i];
        }
    }
}