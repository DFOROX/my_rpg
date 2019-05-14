/*
** EPITECH PROJECT, 2018
** str_to_word_array.c
** File description:
** parce array
*/

#include "my.h"

int my_parce(char c, char *p)
{
    for (int i = 0; p[i]; i++)
        if (p[i] == c)
            return (1);
    return (0);
}

int look_char(char *str, int i, char *p)
{
    for (; str[i] && my_parce(str[i + 1], p); i++);
    return (i);
}

char **my_set_str(char *str, char *p)
{
    char **rtn;
    int j = 2;
    int k = 0;
    int i;

    for (i = 0; str[i]; i++)
        j += my_parce(str[i], p);
    rtn = my_malloc2(sizeof(char *), 0, j + 3);
    for (i = 0; str[i] && my_parce(str[i], p); i++);
    for (j = 0; str[i]; i++) {
        if (my_parce(str[i], p) || !str[i + 1]) {
            rtn[j] = my_malloc2(sizeof(char), k + 4, 1);
            k = 0;
            j++;
            i = look_char(str, i, p);
        } else
            k++;
    }
    return (rtn);
}

char **my_str_to_word_array2(char *str, char *p)
{
    char **rtn = my_set_str(str, p);
    int j = 0;
    int k = 0;
    int i;

    for (i = 0; str[i] && my_parce(str[i], p); i++);
    for (; str[i]; i++) {
        if (!str[i] || my_parce(str[i], p)) {
            k = 0;
            j++;
            i = look_char(str, i, p);
        } else {
            rtn[j][k] = str[i];
            k++;
        }
    }
    rtn[j] = (rtn[j] && !*rtn[j]) ? NULL : rtn[j];
    for (int i = 0; rtn[i]; i++)
        rtn[i] = (rtn[i] && !*rtn[i]) ? NULL : rtn[i];
    return (rtn);
}

char **my_str_to_word_array(char *str, char *p)
{
    if (!str)
        return (NULL);
    else
        return (my_str_to_word_array2(str, p ? p : ""));
}
