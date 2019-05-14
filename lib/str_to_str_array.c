/*
** EPITECH PROJECT, 2018
** str_to_str_array.c
** File description:
** parce array
*/

#include "my.h"

static int my_parce(char *str, char *p, int j)
{
    int i = 0;

    for (; p[i] && str[i + j] == p[i]; i++);
    if (p[i])
        return (0);
    else
        return (my_strlen(p));
}

int look_str(char *str, char *p, int i)
{
    for (; str[i + 2] && my_parce(str, p, i); i++)
        i += my_parce(str, p, i);
    return (i);
}

static char **my_set_str(char *str, char *p)
{
    char **rtn;
    int j = 2;
    int k = 0;
    int i;

    for (i = 0; str[i]; i++) {
        j += (my_parce(str, p, i)) ? 1 : 0;
        i += my_parce(str, p, i);
    }
    rtn = my_malloc2(sizeof(char *), 0, j + 3);
    for (i = 0; str[i] && my_parce(str, p, i); i++)
        i += my_parce(str, p, i);
    for (j = 0; str[i]; i++) {
        if (my_parce(str, p, i) || !str[i + 1]) {
            rtn[j] = my_malloc2(sizeof(char), k + 4, 1);
            k = 0;
            j++;
            i = str[i + 1] ? look_str(str, p, i) - 2 : i + 1;
        } else
            k++;
    }
    return (rtn);
}

char **my_str_to_str_array2(char *str, char *p)
{
    char **rtn = my_set_str(str, p);
    int j = 0;
    int k = 0;
    int i;

    for (i = 0; str[i] && my_parce(str, p, i); i++)
        i += my_parce(str, p, i);
    for (; str[i]; i++) {
        if (!str[i] || my_parce(str, p, i)) {
            k = 0;
            j++;
            i = str[i + 1] ? look_str(str, p, i) - 2 : i + 1;
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

char **my_str_to_str_array(char *str, char *p)
{
    if (!str)
        return (NULL);
    else
        return (my_str_to_str_array2(str, p ? p : ""));
}
