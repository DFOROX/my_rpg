/*
** EPITECH PROJECT, 2018
** edit_file.c
** File description:
** edit_file
*/

#include "../my.h"

char *read_file(char *file)
{
    int fd = open(file, O_RDONLY);
    char tmp[10];
    char *tmp2 = NULL;
    char *rtn = NULL;
    int r = 0;

    if (fd < 0)
        fd = open(PATH_DEFAULT, O_RDONLY);
    while ((r = read(fd, tmp, 10))) {
        tmp[r] = 0;
        tmp2 = my_strcatn(rtn, tmp);
        if (rtn)
            free(rtn);
        rtn = tmp2;
    }
    close(fd);
    return (rtn);
}

void my_putnbr_fd(int fd, int nb)
{
    char c;

    if (nb < 0) {
        write(fd, "-", 1);
        nb *= -1;
    }
    if (nb >= 10)
        my_putnbr_fd(fd, nb / 10);
    c = (nb % 10) + 48;
    write(fd, &c, 1);
}

void my_putstr_fd(int fd, char *str)
{
    int n = 0;

    if (!str)
        return;
    for (; str[n]; n += 1);
    write(fd, str, n);
}
