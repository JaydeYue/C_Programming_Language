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

    //  Determine how many words each bar represent, i.e. step
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

    // if (direction == HORIZONTAL) {
    //
    // } else {
    //
    // }
}
