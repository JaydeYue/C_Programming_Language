/*  Exercise 1-4
    Write a program to print the corresponding Celsius to Fahrenheit table.
*/
#include <stdio.h>

//  Original code from the book with heading added
void c_to_f_table() {
    float fahr, celsius;
    int lower, upper, step;
    lower = -20;      /* lower limit of temperature table */
    upper = 150;    /* upper limit */
    step = 10;      /* step size */
    celsius = lower;
    printf("Celsius to Fahrenheit Table\n");
    while (celsius <= upper) {
        fahr = (celsius * 9.0/5.0) + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
