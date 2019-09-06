//  Used as boolean
#define TRUE 1
#define FALSE 0

//  Max line of any array
#define MAXLINE 1000

//  helpers.c
void recover_stdin(int exercise);
void book_copy(char to[], char from[]);
int get_from_input(char separators[], char line[], int lim);

//  Exercise 3-1
void time_binsearch();
int book_binsearch(int x, int v[], int n);
int my_binsearch(int x, int v[], int n);

//  Exercise 3-2
void escape_to_real(char from[], char to[]);
void real_to_escape(char from[], char to[]);