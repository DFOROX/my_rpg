/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** compare n first value of two string
*/

int my_strncmp(char const *s1, char const *s2, unsigned long n)
{
    char c1 = *s1++;
    char c2 = *s2++;

    while (c1 == c2 && --n != 0) {
        if (c1 == 0 || c2 == 0)
            return (c1 - c2);
        c1 = *s1++;
        c2 = *s2++;
    }
    return (c1 - c2);
}