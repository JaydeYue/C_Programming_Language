/*  Exercise 1-12
    Write a program that prints its input one word per line.
*/
#include <stdio.h>

//  Words are defined to be characters separated by blanks, tabs, and newlines
void one_word_per_line() {
    int temp, count_newline = 0;
    while ((temp = getchar()) != EOF) {
        switch (temp) {
            case '\t': case ' ': case '\n':
                if (count_newline == 0) {
                    putchar('\n');
                }
                count_newline++;
                break;
            default:
                putchar(temp);
                count_newline = 0;
                break;
        }
    }
}
