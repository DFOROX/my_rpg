/*
** EPITECH PROJECT, 2018
** convert_base.c
** File description:
** convert a base in another base
*/

#include <stdlib.h>

int my_getnbr_base(char const *str, char const *base);

char *my_revstr(char *str);

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    char *value;
    int entry_value = my_getnbr_base(nbr, base_from);
    int i = -1;

    value = malloc(sizeof(char) * 11);
    value[10] = 0;
    while (base_to[++i] != 0);
    for (int j = 0; j != 10; j++) {
        value[j] = base_to[(entry_value % i)];
        entry_value /= i;
    }
    value = my_revstr(value);
    while (*value != 0 && *value == 48)
        ++value;
    return (value);
}
