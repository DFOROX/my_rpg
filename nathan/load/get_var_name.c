/*
** EPITECH PROJECT, 2018
** get_var_name.c
** File description:
** get_var_name
*/

#include "../my.h"

bool is_var_name(char *str, char *name, char p)
{
    int i = 0;

    if (!str || !name)
        return (false);
    for (; str[i] && str[i] != p && name[i] == str[i]; i += 1);
    if (name[i] || (str[i] != p && str[i] && str[i + 1] != p))
        return (false);
    else
        return (true);
}

bool is_item_name(char *str, char *name)
{
    int i = 0;

    if (!str || !name)
        return (false);
    for (; str[i] && name[i] == str[i]; i += 1);
    if (name[i])
        return (false);
    else
        return (true);
}
