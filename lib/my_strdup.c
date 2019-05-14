/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** allocate string memory
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    unsigned long i = -1;

    while (src[++i] != 0);
    str = malloc(i + 1);
    for (unsigned long j = 0; j <= i; j += 1)
        str[j] = src[j];
    return (str);
}
