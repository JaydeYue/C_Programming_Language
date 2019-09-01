//  Used as boolean
#define TRUE 1
#define FALSE 0

//  Used as maxline of a string array
#define MAXLINE 1000

/*  From helpers.c*/
//  Store the input read up to one of the separators into line, lim is max size of line, return the length
int get_from_input(char separators[], char line[], int lim);
int book_getline(char s[], int lim);
void book_copy(char to[], char from[]);

// Exercise 2-1
void determine_range();

//  Exercise 2-2
void for_loop_equivalent();
int no_for_loop_getline(char s[], int lim);

//  Exercise 2-3
void htoi();

//  Exercise 2-4
void squeeze(char s1[], char s2[]);

//  Exercise 2-5
int any(char s1[], char s2[]);