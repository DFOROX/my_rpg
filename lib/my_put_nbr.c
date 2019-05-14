/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** print number
*/

#include <unistd.h>

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return (0);
    }
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    nb = nb % 10 + 48;
    write (1, &nb, 1);
    return (0);
}
