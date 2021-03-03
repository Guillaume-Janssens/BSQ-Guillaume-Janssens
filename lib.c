/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** basic functions for bsq
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int min(int a, int b, int c)
{
    int m = a;

    if (m > b)
        m = b;
    if (m > c)
        m = c;
    return (m);
}

char **to_num(char **tab, char *str)
{
    int x = 0;
    int y = 0;

    while (x < tab_counter(str)) {
        while (tab[x][y] != '\0') {
            if (tab[x][y] == '.')
                tab[x][y] = '1';
            else if (tab[x][y] == 'o')
                tab[x][y] = '0';
            y += 1;
        }
        x += 1;
        y = 0;
    }
    return (tab);
}

int tab_counter(char *str)
{
    int tab = str[0] - 48;
    int i = 1;

    while (str[i] != '\n') {
        tab *= 10;
        tab += str[i] - 48;
        i += 1;
    }
    return (tab);
}

int number_counter(int x)
{
    int i = 1;

    while (x > 9) {
        i += 1;
	x /= 10;
    }
    return (i);
}

int line_len(char *str)
{
    int i = number_counter(tab_counter(str)) + 1;

    while (str[i] != '\n' || '\0')
        i += 1;
    return (i);
}
