/*  Exercise 2-7
    Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e. 1 changed into 0 and vice versa), leaving the others unchanged.
*/
#include <stdio.h>
#include "main.h"


int invert(unsigned x, int p, int n) {
    if (p + 1 - n < 0) {
        return -1;
    }
    unsigned mask = ~(~0 << n) << (p + 1 - n);
    unsigned mid_x = mask & ~x;
    unsigned other_x = ~mask & x;
    return mid_x | other_x;
}