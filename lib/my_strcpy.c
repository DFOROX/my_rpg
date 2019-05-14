/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** make a string copy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = -1;

    while (src[++i])
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
