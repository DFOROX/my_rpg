/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** reverse charact order of string
*/

char *my_revstr(char *str)
{
    unsigned long i = 0;
    unsigned long j = -1;
    char swap;

    while (str[++j]);
    --j;
    while (i < j) {
        swap = str[i];
        str[i] = str[j];
        str[j] = swap;
        ++i;
        --j;
    }
    return (str);
}
