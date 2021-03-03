/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** new tab creator
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char what_char(int c)
{
    if (c == 1)
        return ('.');
    else if (c == 0)
        return ('o');
    else if (c == 2)
        return('x');
    return ('$');
}

void back_to_char(int **tab, char *str)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int r = tab_counter(str);
    int c = line_len(str) - (number_counter(tab_counter(str)) + 1);
    char *cpy = malloc(sizeof(char) * (tab_counter(str) * (line_len(str) - (number_counter(tab_counter(str)) + 1)) + tab_counter(str)));

    while (x < tab_counter(str)) {
        while (y < line_len(str) - (number_counter(tab_counter(str)) + 1)) {
            cpy[z] = what_char(tab[x][y]);
            y += 1;
            z += 1;
        }
        cpy[z] = '\n';
        z += 1;
        x += 1;
        y = 0;
    }
    cpy[z - 1] = '\0';
    my_putstr(cpy, (r + (r * c)));
    free(cpy);
}

void make_new_tab(max_t max, int **tab, char *str)
{
    int i, j;

    for (i = max.max_i; i > max.max_i - max.max_of_s; i--) {
        for (j = max.max_j; j > max.max_j - max.max_of_s; j--)
            tab[i][j] = 2;
    }
    back_to_char(tab, str);
}
