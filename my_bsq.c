/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** file for chacking biggest square
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int **my_s_set(int **tab, int r, int c, int **s)
{
    int i, j;
    
    for (i = 0; i < r; i++) {
        s[i] = malloc(sizeof(int) * c);
        s[i][0] = tab[i][0];
    }
    for (j = 0; j < c; j++)
        s[0][j] = tab[0][j];
    return (s);
}

void placer(int **tab, char *str, int **s)
{
    int i, j;
    int r = tab_counter(str);
    int c = line_len(str) - (number_counter(tab_counter(str)) + 1);
    max_t max;

    max.max_of_s = s[0][0];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (max.max_of_s < s[i][j] || (max.max_of_s == s[i][j] && j < max.max_j && i == max.max_i))
            {
                max.max_of_s = s[i][j];
                max.max_i = i;
                max.max_j = j;
            }
        }
    }
    make_new_tab(max, tab, str);
}

void my_algo(int **tab, char *str)
{
    int r = tab_counter(str);
    int c = line_len(str) - (number_counter(tab_counter(str)) + 1);
    int i, j = 0;
    int **s = malloc(sizeof(int *) * r);

    s = my_s_set(tab, r, c, s);
    for (i = 1; i < r; i++) {
        for (j = 1; j < c; j++) {
            s[i][j] = one_or_zero(tab[i][j], s, i, j);
        }
    }
    placer(tab, str, s);
}

int convert_to_tab(char *str)
{
    int **tab = malloc(sizeof(int *) * (tab_counter(str)));
    int line = 0;
    int row = 0;
    int i = number_counter(tab_counter(str)) + 1;

    if (tab_counter(str) == 1 || (str[i + 1] == '\n' || str[i + 1] == '\0')) {
        my_exeption(str, i);
        return (0);
    }
    while (str[i] != '\0') {
        tab[line] = malloc(sizeof(int) * (line_len(str)));
        while (str[i] != '\n' && str[i] != '\0') {
            tab[line][row] = change_char_to_digit(str[i]);
            i += 1;
            row += 1;
        }
        i += 1;
        line += 1;
        row = 0;
    }
    my_algo(tab, str);
    return (0);
}

int my_bsq(char const *filepath)
{
    int i = 0;
    int fd;
    struct stat buf;
    char *buffer;

    stat(filepath, &buf);
    buffer = malloc(sizeof(char) * (buf.st_size + 2));
    fd = open(filepath, O_RDWR);
    if (buffer == NULL)
        return (84);
    if (fd == -1)
        return (84);
    i = read(fd, buffer, buf.st_size);
    if (i == -1)
        return (84);
    buffer[i] = '\0';
    close(fd);
    convert_to_tab(buffer);
    free(buffer);
    return (0);
}
