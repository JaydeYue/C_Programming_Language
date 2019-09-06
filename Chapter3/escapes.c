/*  Exercise 3-2
    Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
*/
#include <stdio.h>
#include "main.h"

void escape_to_real(char from[], char to[]) {
    int if_slash = FALSE;
    for (int i=0, j=0; from[i] != EOF && from[i] != '\0'; i++, j++) {
        switch (from[i]){
        case '\\':
            if_slash = TRUE;
            j--;
            break;
        case 'n':
            if (if_slash)
                to[j] = '\n';
            else
                to[j] = 'n';
            if_slash = FALSE;
            break;
        case 't':
            if (if_slash)
                to[j] = '\t';
            else
                to[j] = 't';
            if_slash = FALSE;
            break;
        case 'b':
            if (if_slash)
                to[j] = '\b';
            else
                to[j] = 'b';
            if_slash = FALSE;
            break;
        default:
            if (if_slash)
                to[j++] = '\\';
            if_slash = FALSE;
            to[j] = from[i];
            break;
        }
    }
}

void real_to_escape(char from[], char to[]) {
    for (int i=0, j=0; from[i] != EOF && from[i] != '\0'; i++, j++) {
        switch (from[i]){
        case '\n':
            to[j++] = '\\';
            to[j] = 'n';
            break;
        case '\t':
            to[j++] = '\\';
            to[j] = 't';
            break;
        case '\b':
            to[j++] = '\\';
            to[j] = 'b';
            break;
        default:
            to[j] = from[i];
            break;
        }
    }
}