/*  Exercise 1-13
    Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/
#include <stdio.h>
#include <math.h>
#include "main.h"

//  Words are defined to be characters separated by blanks, tabs, and newlines with less than or equal to 50 characters
void word_length_histogram(int direction) {
    //  Process inputs
    int temp, count_word = 0;
    int word_length[50] = {0};
    while ((temp = getchar()) != EOF) {
        switch (temp) {
            case '\t': case ' ': case '\n':
                if (count_word != 0 && count_word <= 50) {
                    word_length[count_word-1]++;
                }
                count_word = 0;
                break;
            default:
                count_word++;
                break;
        }
    }

    //  Determine how many words each bar represent
    int i, max = 0, step;
    for (i=0; i < 50; i++) {
        if (word_length[i] > max) {
            max = word_length[i];
        }
    }
    if (max <= 50) {
        step = 1;
    } else {
        step = ceil(max/50.0);
    }

    int j;
    max = floor(max/step);
    printf("Histogram of Word Lengths with Each Bar Representing %d Words\n", step);
    printf("-------------------------------------------------------------\n");
    if (direction == HORIZONTAL) {
        for (i=0; i<50; i++) {
            printf("%d", i+1);
            if (i < 9)
                printf(" ");
            printf("|");
            printf(" ");
            for (j=0; j<word_length[i]; j++)
                printf("-");
            if (word_length[i] != 0) {
                printf(" ");
            }
            printf("%d\n", word_length[i]);
        }
    } else {
        printf(" 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        int position, num_digit, num_bar;
        for (i = 0; i < 50; i++) {
            if (i > max) {
                break;
            } else {
                position = 0;
                for (j = 0; j < 50; j++) {
                    while (position < j*3) {
                        printf(" ");
                        position++;
                    }
                    num_bar = floor(word_length[j]/step);
                    if (num_bar > i) {
                        if (position == j*3) {
                            printf(" ");
                            position++;
                        }
                        printf("|");
                        position++;
                    } else if (num_bar == i) {
                        num_digit = count_digit(word_length[j]);
                        if (position == j*3 && num_digit <= 1) {
                            printf(" ");
                            position++;
                        }
                        printf("%d", word_length[j]);
                        position += (num_digit != 0) ? num_digit : 1;
                    }
                }
            }
            printf("\n");
        }
    }
}

int count_digit(int input) {
    int count = 0;
    while (input > 0) {
        input = floor(input/10);
        count++;
    }
    return count;
}
