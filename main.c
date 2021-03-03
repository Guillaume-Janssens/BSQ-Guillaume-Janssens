
/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** main for BSQ
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *load_file(char const *filepath)
{
    int i = 0;
    int fd;
    struct stat buf;
    char *buffer;

    stat(filepath, &buf);
    buffer = malloc(sizeof(char) * (buf.st_size + 2));
    fd = open(filepath, O_RDWR);
    if (buffer == NULL)
        return (NULL);
    if (fd == -1)
        return (NULL);
    i = read(fd, buffer, buf.st_size);
    if (i == -1)
        return (NULL);
    buffer[i - 1] = ' ';
    buffer[i] = '\0';
    close(fd);
    return (buffer);
}

int check_all_char(char *str)
{
    int i = number_counter(tab_counter(str)) + 1;

    while (str[i] != '\0') {
        if (str[i] != '.' && str[i] != 'o' && str[i] != '\n' && str[i] != ' ')
            return (84);
        i += 1;
    }
    return (0);
}

int check_errors(int argc, char *str)
{
    char *buffer = load_file(str);
    
    if (argc != 2)
        return (84);
    else if (buffer == NULL || tab_counter(buffer) == 0 ||
             check_all_char(buffer) == 84)
        return (84);
    else
        return (0);
}

int main(int argc, char **argv)
{
    int err = check_errors(argc, argv[1]);
    if (err == 84)
        return (84);
    else {
        if (my_bsq(argv[1]) == 84)
            return (84);
    }
    return (0);
}
