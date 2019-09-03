/*  Exercise 2-6
    Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.

    We assume that bit position 0 is at the right end and that n and p are sensible positive values. For
*/
#include <stdio.h>
#include "main.h"

int setbits(unsigned x, int p, int n, unsigned y) {
    if (p + 1 - n < 0) {
        return -1;
    }
    unsigned mask = ~(~0 << n);     //  n bits of 1
    mask <<= (p + 1 - n);           //  get to right position at p
    y = book_getbits(y, n-1 , n);   //  get y
    y = y << (p + 1 -n);            //  get y to right position
    x = ~mask & x;                  //  set n bits starting from p = 0
    x = x | y;                      //  set those bits to y
    return x;
}
