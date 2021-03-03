/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** second file of usefull functions
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char *str, int size)
{
    str[size - 1] = '\n';
    write(1, str, size);
}

int change_char_to_digit(char c)
{
    if (c == '.')
        return (1);
    else if (c == 'o')
        return (0);
    return (42);
}

int one_or_zero(int n, int **s, int i, int j)
{
    if (n == 1)
        return (min(s[i][j-1], s[i-1][j], s[i-1][j-1]) + 1);
    else
        return (0);
}
