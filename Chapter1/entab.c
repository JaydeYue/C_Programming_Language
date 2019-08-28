/*  Exercise 1-21
    Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
*/
#include <stdio.h>
#include "main.h"

//  The output may show up weird on console because the terminal sometimes does not use a set tab length
void entab(int tablength) {
    int temp, i, count_char = 0, count_tab = 0, count_space = 0, num_blank;
    while ((temp = getchar()) != EOF) {
        switch (temp) {
            case '\t':
                count_tab++;
                count_char = 0;
                break;
            case ' ':
                count_space++;
                count_char = 0;
                break;
            default:
                if (count_char == 0) {
                    num_blank = count_tab*tablength + count_space;
                    count_tab = num_blank/tablength;
                    count_space = num_blank - count_tab*tablength;
                    for (i = 0; i < count_tab; i++)
                        putchar('\t');
                    for (i = 0; i < count_space; i++)
                        putchar(' ');
                }
                putchar(temp);
                count_char++;
                count_tab = count_space = 0;
                break;
        }
    }
}