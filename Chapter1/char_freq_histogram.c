/*  Exercise 1-14
    Write a program to print a histogram of the frequencies of different characters in its input.
*/
#include <stdio.h>
#include <math.h>
#include "main.h"

void char_freq_histogram(int direction) {
    //  Process inputs
    int temp;
    //  a...z, digits, \n \t space, others
    int char_freq[29] = {0};
    while ((temp = getchar()) != EOF) {
        if ('A' <= temp && temp <= 'Z') {
            char_freq[temp - 'A']++;
        } else if ('a' <= temp && temp <= 'z') {
            char_freq[temp - 'a']++;
        } else if ('0' <= temp && temp <= '9') {
            char_freq[26]++;
        } else if (temp == '\t' || temp == ' ' || temp == '\n') {
            char_freq[27]++;
        } else {
            char_freq[28]++;
        }
    }

    //  Determine how many characters each bar represent
    int i, max = 0, step;
    for (i=0; i < 29; i++) {
        if (char_freq[i] > max) {
            max = char_freq[i];
        }
    }
    if (max <= 50) {
        step = 1;
    } else {
        step = ceil(max/50.0);
    }

    int j;
    max = max/step;
    int num_bar[29];
    for (i = 0; i < 29; i++)
        num_bar[i] = char_freq[i]/step;
    printf("Histogram of Frequencies of Characters with Each Bar Representing %d Characters\n", step);
    printf("The chracters are grouped into 26 letters (upper and lower cases are not distinguished), digits (D), separating characters (S: tab newline space), and other characters (O) \n");
    printf("-------------------------------------------------------------------------------\n");
    if (direction == HORIZONTAL) {
        for (i=0; i<29; i++) {
            if (i < 26) {
                printf("%c", i + 'a');
            } else if (i == 26) {
                printf("D");
            } else if (i == 27) {
                printf("S");
            } else if (i == 28) {
                printf("O");
            }
            printf("|");
            printf(" ");
            for (j=1; j<=num_bar[i]; j++)
                printf("-");
            if (char_freq[i] >= step) {
                printf(" ");
            }
            printf("%d\n", char_freq[i]);
        }
    } else {
        printf(" a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  D  S  O\n");
        printf("--------------------------------------------------------------------------------------\n");
        int position, num_digit;
        for (i = 0; i < 50; i++) {
            if (i > max) {
                break;
            } else {
                position = 0;
                for (j = 0; j < 29; j++) {
                    while (position < j*3) {
                        printf(" ");
                        position++;
                    }
                    if (num_bar[j] > i) {
                        if (position == j*3) {
                            printf(" ");
                            position++;
                        }
                        printf("|");
                        position++;
                    } else if (num_bar[j] == i) {
                        num_digit = count_digit(char_freq[j]);
                        if (position == j*3 && num_digit <= 1) {
                            printf(" ");
                            position++;
                        }
                        printf("%d", char_freq[j]);
                        position += (num_digit != 0) ? num_digit : 1;
                    }
                }
            }
            printf("\n");
        }
    }
}
