/*  Exercise 1-24
    Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don’t forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)
*/
#include <stdio.h>
#include "main.h"

void syntax_checker() {
    int temp, line_count = 1, err_count = 0;
    int on_long_comment, on_line_comment, on_single, on_double;
    int prev_symbol_what;
    int par_count, bracket_count, brace_count;
    int closure_stack[MAXLINE];
    int stack_index = 0;
    on_long_comment = on_line_comment = on_single = on_double = FALSE;
    prev_symbol_what = OTHER_CHAR;
    par_count = bracket_count = brace_count = 0;
    while ((temp = getchar()) != EOF) {
        //  Comments
        if (on_long_comment) {
            switch (temp) {
            case '/':
                if (prev_symbol_what == STAR) {
                    on_long_comment = FALSE;
                    prev_symbol_what = OTHER_CHAR;
                } else {
                    prev_symbol_what = OTHER_CHAR;
                }
                break;
            case '*':
                prev_symbol_what = STAR;
                break;
            default:
                prev_symbol_what = OTHER_CHAR;
                break;
            }
        } else if (on_line_comment) {
            if (temp == '\n') {
                on_line_comment = FALSE;
                prev_symbol_what = OTHER_CHAR;
            }
        //  Quotation
        } else if (on_double) {
            if (prev_symbol_what != ESCAPE && temp == '"') {
                on_double = FALSE;
                prev_symbol_what = OTHER_CHAR;
            } else if (temp == '\\') {
                if (prev_symbol_what != ESCAPE) {
                    prev_symbol_what = ESCAPE;
                } else {
                    prev_symbol_what = OTHER_CHAR;
                }
            } else {
                prev_symbol_what = OTHER_CHAR;
            }
        } else if (on_single) {
            if (prev_symbol_what != ESCAPE && temp == '\'') {
                on_single = FALSE;
                prev_symbol_what = OTHER_CHAR;
            } else if (temp == '\\') {
                if (prev_symbol_what != ESCAPE) {
                    prev_symbol_what = ESCAPE;
                } else {
                    prev_symbol_what = OTHER_CHAR;
                }
            } else {
                prev_symbol_what = OTHER_CHAR;
            }
        } else {
            switch (temp) {
            //  Comments
            case '/':
                if (prev_symbol_what == SLASH) {
                    on_line_comment = TRUE;
                    prev_symbol_what = OTHER_CHAR;
                } else {
                    prev_symbol_what = SLASH;
                }
                break;
            case '*':
                if (prev_symbol_what == SLASH) {
                    on_long_comment = TRUE;
                    prev_symbol_what = OTHER_CHAR;
                } else {
                    prev_symbol_what = STAR;
                }
                break;
            //  Quotation
            case '"':
                on_double = TRUE;
                prev_symbol_what = OTHER_CHAR;
                break;
            case '\'':
                on_single = TRUE;
                prev_symbol_what = OTHER_CHAR;
                break;
            //  Closures
            case '(':
                par_count++;
                prev_symbol_what = OTHER_CHAR;
                closure_stack[stack_index] = PARENTHESE;
                // printf("A:%d", stack_index);
                stack_index++;
                break;
            case '{':
                brace_count++;
                prev_symbol_what = OTHER_CHAR;
                closure_stack[stack_index] = BRACE;
                // printf("B:%d", stack_index);
                stack_index++;
                break;
            case '[':
                bracket_count++;
                prev_symbol_what = OTHER_CHAR;
                closure_stack[stack_index] = BRACKET;
                // printf("C:%d", stack_index);
                stack_index++;
                break;
            case ')':
                par_count--;
                if (par_count == -1) {
                    printf("There are more closing parentheses than needed at line %d\n", line_count);
                    err_count++;
                } else if (closure_stack[stack_index-1] != PARENTHESE) {
                    printf("The closing parenthese at line %d is not appropriate\n", line_count);
                    // printf("D:%d", stack_index);
                    err_count++;
                } else {
                    stack_index--;
                }
                prev_symbol_what = OTHER_CHAR;
                break;
            case '}':
                brace_count--;
                if (brace_count == -1) {
                    printf("There are more closing braces than needed at line %d\n", line_count);
                    err_count++;
                } else if (closure_stack[stack_index-1] != BRACE) {
                    printf("The closing brace at line %d is not appropriate\n", line_count);
                    // printf("E:%d", stack_index);
                    err_count++;
                } else {
                    stack_index--;
                }
                prev_symbol_what = OTHER_CHAR;
                break;
            case ']':
                bracket_count--;
                if (bracket_count == -1) {
                    printf("There are more closing brackets than needed at line %d\n", line_count);
                    err_count++;
                } 
                if (closure_stack[stack_index-1] != BRACKET) {
                    printf("The closing bracket at line %d is not appropriate\n", line_count);
                    // printf("F:%d", stack_index);
                    err_count++;
                } else {
                    stack_index--;
                }
                prev_symbol_what = OTHER_CHAR;
                break;
            case '\n':
                if (line_count == 1) {
                    printf("\n");
                    printf("\n");
                }
                line_count++;
                prev_symbol_what = OTHER_CHAR;
                break;
            default:
                prev_symbol_what = OTHER_CHAR;
                break;
            }
        }
    }
    if (on_double) {
        printf("Double quotation has not been closed\n");
        err_count++;
    } else if (on_single) {
        printf("Single quotation has not been closed\n");
        err_count++;
    }
    if (par_count != 0) {
        if (par_count > 0) {
            printf("There are not enough closing parentheses\n");
            err_count++;
        } else {
            printf("There are more closing parentheses than needed\n");
            err_count++;
        }
    } else if (brace_count != 0) {
        if (brace_count > 0) {
            printf("There are not enough closing braces\n");
            err_count++;
        } else {
            printf("There are more closing braces than needed\n");
            err_count++;
        }
    } else if (bracket_count != 0) {
        if (bracket_count > 0) {
            printf("There are not enough closing brackets\n");
            err_count++;
        } else {
            printf("There are more closing brackets than needed\n");
            err_count++;
        }
    }

    if (err_count == 0) {
        printf("Congrats! There are no syntax errors detected in your C program!\n");
    } else {
        printf("There are %d errors detected in your C program\n", err_count);
    }
}