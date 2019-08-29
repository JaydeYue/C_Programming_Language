//  Used as boolean
#define TRUE 1
#define FALSE 0

#define HORIZONTAL 0                        //  1-13, 1-14
#define VERTICAL 1                          //  1-13, 1-14
#define MAXLINE 1000                        //  1-16, 1-17, 1-19, 2-24
#define TABLENGTH 4                         //  1-20, 1-21
#define COLUMN_TO_WRAP 80                   //  1-22
#define OTHER_CHAR 0                        //  1-24
#define ESCAPE 1                            //  1-24
#define SLASH 2                             //  1-24
#define STAR 3                              //  1-24
#define PARENTHESE 1                        //  1-24
#define BRACKET 2                           //  1-24
#define BRACE 3                             //  1-24

//  Exercise 1-1
void hello_world();

//  Exercise 1-2
// void print_invalids();

//  Exercise 1-3
void f_to_c_table();

//  Exercise 1-4
void c_to_f_table();

//  Exercise 1-5
void f_to_c_reverse();

//  Exercise 1-6
void verify_expression();

//  Exercise 1-7
void print_EOF();

//  Exercise 1-8
void count_special_char();

//  Exercise 1-9 & 1-10
void special_char_replace();

//  Exercise 1-12
void one_word_per_line();

//  Exercise 1-13
void word_length_histogram(int direction);
int count_digit(int input);                 //  Also used in exercise 1-14

//  Exercise 1-14
void char_freq_histogram(int direction);

//  Exercise 1-15
void f_to_c_with_func();
float f_to_c(float fahr);

//  Exercise 1-16
void longest_line_no_limit();
int book_getline(char line[], int maxline); //  Also used in exercise 1-17, 1-19, 1-22
void book_copy(char to[], char from[]);     //  Also used in exercise 1-17

//  Exercise 1-17
void inputs_longer_than(int length);

//  Exercise 1-18
void rm_trailing();

//  Exercise 1-19
void inputs_reverse();
int reverse(char original[], char reversed[]);

//  Exercise 1-20
//  Making tablength a variable to make the function more functional
void detab(int tablength);                  
//  Defining the TABLENGTH to ensure consistency

//  Exercise 1-21
void entab(int tablength);

//  Exercise 1-22
void fold(int column_to_wrap);
void putline(char line[], int limit);

//  Exercise 1-23
void rm_c_comments();

//  Exercise 1-24
void syntax_checker();