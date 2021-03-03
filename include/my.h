/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** my.h for bsq
*/

//structures

typedef struct max_s
{
    int max_of_s;
    int max_i;
    int max_j;
}max_t;

extern max_t max;

//basic function

int tab_counter(char *str);
int line_len(char *str);
int number_counter(int x);

//functions called by main

int my_bsq(char const *filepath);

//other functions called by bsq.c

char **to_num(char **tab, char *str);
void make_new_tab(max_t max, int **tab, char *str);
int min(int a, int b, int c);

//lib_two functions

int change_char_to_digit(char c);
int one_or_zero(int n, int **s, int i, int j);
void my_putstr(char *str, int size);

//exeption file functions

void my_exeption(char *str, int i);
