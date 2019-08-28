/*  Exercise 1-15
    Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
*/
#include <stdio.h>
#include "main.h"

void f_to_c_with_func() {
    float fahr;
    int lower, upper, step;
    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */
    fahr = lower;
    printf("Fahrenheit to Celsius Table Using Function\n");
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, f_to_c(fahr));
        fahr = fahr + step;
    }
}

float f_to_c(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}
