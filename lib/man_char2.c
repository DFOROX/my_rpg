/*
** EPITECH PROJECT, 2018
** man_char.c
** File description:
** basic fonctions
*/

#include "my.h"

char *my_nbrstr(int nb)
{
    char *str = malloc(16);
    int i = -1;

    for (int i = 0; i < 13; i++)
        str[i] = (i == 0) ? '0' : '\0';
    for (int compt =  nb; compt >= 1; i++)
        compt = compt / 10;
    for (; nb >= 1; i--) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    return (str);
}

char *my_strcatn(char *str1, char *str2)
{
    int i;
    int j;
    char *str3;

    for (i = 0; str1 && str1[i]; i++);
    for (j = 0; str2 && str2[j]; j++);
    str3 = malloc(i + j + 1);
    str3[i + j] = 0;
    for (i = 0; str1 && str1[i]; i++)
        str3[i] = str1[i];
    for (j = 0; str2 && str2[j]; j++)
        str3[i + j] = str2[j];
    return (str3);
}

bool my_strcmpn(char *str1, char *str2)
{
    int i = 0;

    if (!str1 || !str2)
        return (false);
    for (; str1[i] == str2[i] && str1[i]; i++);
    return ((!str1[i] && !str2[i]) ? true : false);
}

char *my_strcpyn(char *str)
{
    char *rtn;
    int i;

    if (!str)
        return (NULL);
    for (i = 0; str[i]; i++);
    rtn = malloc(i + 1);
    rtn[i] = '\0';
    for (i = 0; str[i]; i++)
        rtn[i] = str[i];
    return (rtn);
}

void *my_malloc2(size_t byte, size_t size, size_t n)
{
    void *rtn = malloc(byte * ((n == 1) ? size : n));

    if (!rtn)
        return (NULL);
    if (n == 1) {
        for (unsigned long i = 0; i < size; i += 1)
            ((unsigned char *)rtn)[i] = '\0';
        return (rtn);
    }
    for (unsigned long i = 0; i < n; i += 1)
        ((unsigned char **)rtn)[i] = NULL;
    return (rtn);
}
