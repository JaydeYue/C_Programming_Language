/*  Exercise 2-8
    Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions.
    
    Right rotate: after right shift, the bits that are shifted out gets put to the left
*/
#include <stdio.h>
#include "main.h"

unsigned rightrot(unsigned int x, int n) {
    for (; n != 0; n--) {
        if (x & 1) {
            x = (x >> 1) | (1 << (sizeof(unsigned int)*__CHAR_BIT__-1));
        } else {
            x >>= 1;
        }
    }
    return x;
}