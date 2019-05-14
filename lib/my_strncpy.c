/*
** EPITECH PROJECT, 2018
** my_strncp.c
** File description:
** copy n src's char in dest
*/

char *my_strncpy(char *dest, char const *src, unsigned long n)
{
    char *tmp = dest;

    if (!dest || !src || !n)
        return (dest);
    while (src && n != (unsigned long) (-1)) {
        *tmp = *src;
        ++src;
        ++tmp;
        --n;
    }
    *tmp = 0;
    return (dest);
}
