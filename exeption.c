/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** exeption file functions
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

void my_exeption(char *str, int i)

{
    int j = i;

    while (str[i] != '.' && str[i] != '\0')
        i += 1;
    if (str[i] == '.') {
        str[i] = 'x';
    }
    while (str[j] != '\0') {
        write(1, &str[j], 1);
        j += 1;
    }
}
