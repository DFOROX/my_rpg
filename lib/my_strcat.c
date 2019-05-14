/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** copy cat function
*/

char *my_strcat(char *dest, char const *src)
{
    char *tmp = dest;

    if (!dest || !src)
        return (dest);
    while (*tmp != 0)
        ++tmp;
    while (*src != 0) {
        *tmp = *src;
        ++tmp;
        ++src;
    }
    *tmp = 0;
    return (dest);
}