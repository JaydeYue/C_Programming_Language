//  Used as boolean
#define TRUE 1
#define FALSE 0

//  Used as maxline of a string array
#define MAXLINE 1000

/*  From main.c*/
//  Recover stdin from EOF while avoiding puting a \0 at the front of the line
void recover_stdin(int exercise);

/*  From helpers.c*/
//  Store the input read up to one of the separators into line, lim is max size of line, return the length
int get_from_input(char separators[], char line[], int lim);
int read_decimal_from_line(char line[]);
int book_getline(char s[], int lim);
void book_copy(char to[], char from[]);
unsigned book_getbits(unsigned x, int p, int n);
void print_in_binary(unsigned number);

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

//  Exercise 2-6
int setbits(unsigned x, int p, int n, unsigned y);

//  Exercise 2-7
int invert(unsigned, int p, int n);

//  Exercise 2-8
unsigned rightrot(unsigned int x, int n);

//  Exercise 2-9
int bitcount(unsigned x);

//  Exercise 2-10
int lower(int c);