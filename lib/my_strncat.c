/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** add n char in str to another str
*/

char *my_strncat(char *dest, char const *src, unsigned long n)
{
    char *str = dest;

    if (!dest || !src)
        return (dest);
    while (*str)
        ++str;
    for (unsigned long i = 0; *src && i < n; str += 1, src += 1, i += 1)
        *str = *src;
    *str = 0;
    return (dest);
}