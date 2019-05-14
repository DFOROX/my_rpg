/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** compare the value of two string
*/

int my_strcmp(char const *s1, char const *s2)
{
    char c1 = *s1++;
    char c2 = *s2++;

    while (c1 == c2) {
        if (c1 == 0 || c2 == 0)
            return (c1 - c2);
        c1 = *s1;
        c2 = *s2;
        s1++;
        s2++;
    }
    return (c1 - c2);
}
