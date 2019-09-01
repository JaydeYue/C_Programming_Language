/*  Exercise 2-1
    Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "main.h"

void determine_range() {
    printf("Ranges from standard headers limits.h and float.h:\n");
    //  From limits.h
    printf("Number of bits in a byte: %d\n", CHAR_BIT);
    printf("Range of signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned char: 0 to %u\n", UCHAR_MAX);
    printf("Range of unsigned short: 0 to %u\n", USHRT_MAX);
    printf("Range of unsigned int: 0 to %u\n", UINT_MAX);
    printf("Range of unsigned long: 0 to %lu\n", ULONG_MAX);
    //  From float.h
    printf("Range of float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Range of double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Range of long double: %Le to %Le\n\n", LDBL_MIN, LDBL_MAX);

    unsigned char c = ~0;
    unsigned short s = ~0;
    unsigned int i = ~0;
    unsigned long l = ~0;

    printf("Ranges from computation:\n");
    //  Right shift to leave out the sign bit
    printf("Range of signed char: %d to %d\n", -(c >> 1) - 1, c >> 1);
    printf("Range of signed short: %d to %d\n", -(s >> 1) - 1, s >> 1);
    printf("Range of signed int: %d to %d\n", -(i >> 1) - 1, i >> 1);
    printf("Range of signed long: %ld to %ld\n", -(l >> 1) - 1, l >> 1);
    //  They are maximum already since they have all their bits reversed from all 0s
    printf("Range of unsigned char: 0 to %u\n", c);
    printf("Range of unsigned short: 0 to %u\n", s);
    printf("Range of unsigned int: 0 to %u\n", i);
    printf("Range of unsigned long: 0 to %lu\n", l);

    //  The method of computation of floating ranges is from stackoverflow
    float f = 0.0, ftest = 0.0, flast_max;
    double d = 0.0, dtest = 0.0, dlast_max;
    // float f = 0.0, ftest = 0.0, flast_max, flast_min;
    // double d = 0.0, dtest = 0.0, dlast_max, dlast_min;
    // long double ld = 0.0, ldtest = 0.0, ldlast_max, ldlast_min;

    //  The loop terminates when fltest reaches +Inf, as at that point fl = (fl + fltest) - fltest becomes NaN, which is unequal to 0.0.  last contains a value which when added to 1111e28 produces +Inf and so is close to the upper limit of float.
    while (f == 0.0) {
        flast_max = ftest;
        //  1111e28 is chosen to reach +Inf reasonably quickly; it also needs to be large enough that when added to large values the loop continues to progress i.e. it is at least as large as the gap between the largest and second-largest non-infinite float values.
        //  https://stackoverflow.com/questions/24144274/explain-this-code-in-kr-2-1
        ftest += 1111e28;
        f = (f + ftest) - ftest;
    }
    // f = 0.0;
    // while (f == 0.0) {
    //     flast_min = ftest;
    //     ftest -= 1111e28;
    //     f = (f + ftest) - ftest;
    // }

    while (d == 0.0) {
        dlast_max = dtest;
        dtest += 1111e297;
        d = (d + dtest) - dtest;
    }
    // d = 0.0;
    // while (d == 0.0) {
    //     dlast_min = dtest;
    //     dtest -= 1111e297;
    //     d = (d + dtest) - dtest;
    // }

    // while (ld == 0.0) {
    //     ldlast_max = ldtest;
    //     ldtest += 1111e2976;
    //     ld = (ld + ldtest) - ldtest;
    // }
    // ld = 0.0;
    // while (ld == 0.0) {
    //     ldlast_min = ldtest;
    //     ldtest -= 1111e2976;
    //     ld = (ld + ldtest) - ldtest;
    // }
    printf("Maximum of float: %e\n", flast_max);
    printf("Maximum of double: %e\n", dlast_max);
    // printf("Range of float: %e to %e\n", flast_min, flast_max);
    // printf("Range of double: %e to %e\n", dlast_min, dlast_max);
    // printf("Range of long double: %Le to %Le\n", ldlast_min, ldlast_max);
    //  TODO: figure out a good constant for other floating calculations too
}