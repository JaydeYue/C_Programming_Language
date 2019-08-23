/*  Exercise 1-2
    Experiment to find out what happens when printf’s argument string contains \c, where c is some character not listed
    above.
*/
#include <stdio.h>

//  Results in warnings when complied and prints out the character in some cases, nothing in other cases
void print_invalids() {
    printf("\\c: \c \n");
    printf("\\d: \d \n");
    printf("\\e: \e \n");
    printf("\\g: \g \n");
}
