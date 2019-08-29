/*  Exercise 1-23
    Write a program to remove all comments from a C program. Don’t forget to handle quoted strings and character constants properly. C comments do not nest.
*/
#include <stdio.h>
#include "main.h"

void rm_c_comments() {
    int on_long_comment = FALSE, on_line_comment = FALSE, prev_slash = FALSE, prev_star = FALSE;
    int temp;
    while ((temp = getchar()) != EOF) {
        if (on_long_comment) {
            switch (temp) {
            case '/':
                if (prev_star)
                    on_long_comment = FALSE;
                prev_star = FALSE;
                break;
            case '*':
                prev_star = TRUE;
                break;
            default:
                prev_star = FALSE;
                break;
            }
        } else if (on_line_comment) {
            if (temp == '\n') {
                on_line_comment = FALSE;
                putchar('\n');
            }
        } else {
            switch (temp) {
            case '/':
                if (prev_slash) {
                    on_line_comment = TRUE;
                    prev_star = prev_slash = FALSE;
                } else {
                    prev_slash = TRUE;
                    prev_star = FALSE;
                }
                break;
            case '*':
                if (prev_slash) {
                    on_long_comment = TRUE;
                    prev_star = prev_slash = FALSE;
                } else {
                    prev_star = TRUE;
                    prev_slash = FALSE;
                }
                break;
            default:
                if (prev_slash)
                    putchar('/');
                if (prev_star)
                    putchar('*');
                putchar(temp);
                prev_star = prev_slash = FALSE;
                break;
            }
        }
    }
}