/*  Exercise 3-1
    Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.
*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "main.h"

void time_binsearch() {
    clock_t start, end;
    long double time_taken;
    int array[MAXLINE];
    srand(time(NULL));
    array[0] = 0;
    for (int i=1; i < MAXLINE; i++)
        array[i] = rand() % 100 + array[i-1];
    int index = rand() % 1000;
    int result;
    
    start = clock();
    result = book_binsearch(array[index], array, MAXLINE);
    end = clock();
    time_taken = ((double) (end - start)) / (CLOCKS_PER_SEC/1000.0);
    if (result != index)
        printf("Error with book_binsearch\n");
    else
        printf("It takes %.10Lf miliseconds to search with book_binsearch with result at index %d\n", time_taken, index);

    start = clock();
    result = my_binsearch(array[index], array, MAXLINE);
    end = clock();
    time_taken = ((double) (end - start)) / (CLOCKS_PER_SEC/1000.0);
    if (result != index)
        printf("Error with my_binsearch\n");
    else
        printf("It takes %.10Lf miliseconds to search with my_binsearch with result at index %d\n", time_taken, index);
}

/* From the book - binsearch:  find x in v[0] <= v[1] <= ... <= v[n−1] */
int book_binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;    /* no match */
}

int my_binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    //  Exit when low == high since C always rounds down in integer division
    while (low < high) {
        mid = (low+high)/2.0;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (v[high] == x) ? high : -1;
}