/*  Exercise 2-9
    In a two’s complement number system, x &= (x−1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.

    WHY: because if the last bit is 1, x &= (x-1) evaluates to x-1 which is x with right most 1 bit deleted; if the last bit is 0, x-1 will have 0 on the position of the rightmost 1 bit in x, and the 'and' bitwise operator clears that to 0 in x too.
*/
#include <stdio.h>
#include "main.h"

/* bitcount:  count 1 bits in x */
int bitcount(unsigned x) {
    int b = 0;
    while (x) {
        b++;
        x &= (x-1);
    }
    return b;
}