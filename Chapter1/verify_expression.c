/*  Exercise 1-6 & 1-7
    Verify that the expression getchar() != EOF is 0 or 1.
    Write a program to print the value of EOF.
*/
#include <stdio.h>

void verify_expression() {
    int value_of_expression;    // to be verified
    int temp;   //char
    printf("In while loop:\n");
    while ((value_of_expression = ((temp = getchar()) != EOF))) {
        printf("Value of expression: %d;  Value of char %c is: %d\n", value_of_expression, temp, temp);
    }
    printf("Out of while loop:\n");
    printf("Value of expression: %d;  Value of char %c is: %d\n", value_of_expression, temp, temp);
}
