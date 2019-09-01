/*  Exercise 2-3
    Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
*/
#include <stdio.h>
#include "main.h"

void htoi() {
    unsigned long value = 0;
    int if_invalid = FALSE;
    int c = getchar();
    while (c != EOF) {
        // printf("1C: %c\n", c);
        while (c != '\n' && c != '\t' && c != ' ') {
            // printf("2C: %c\n", c);
            if (c <= '9' && c >= '0') {
                value = value*16 + c - '0';
            } else if (c <= 'F' && c >= 'A') {
                value = value*16 + c - 'A' + 10;
            } else if (c <= 'f' && c >= 'a') {
                value = value*16 + c - 'a' + 10;
            } else if (c == 'X' || c == 'x') {
                if (value != 0 && !if_invalid) {
                    printf("Invalid hex number, please try again!\n");
                    if_invalid = TRUE;
                }
            } else {
                if (!if_invalid) {
                    printf("Invalid hex number, please try again!\n");
                    if_invalid = TRUE;
                }
            }
            c = getchar();
        }
        if (if_invalid == TRUE) {
            if_invalid = FALSE;
        } else {
            printf("Your hex number is %lu in decimal\n", value);
        }
        value = 0;
        c = getchar();
    }
}