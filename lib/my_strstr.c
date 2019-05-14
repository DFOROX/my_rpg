/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** search a keyword in string
*/

char *my_strstr(char *str, char const *to_find)
{
    char const *tmp = to_find;

    for (; *str != 0 && *str != *to_find; str += 1);
    if (*str == 0)
        return ((void *) (0));
    for (unsigned long i = 0; str[i] != 0 && *tmp != 0; i += 1, tmp += 1)
        if (str[i] != *tmp)
            return (my_strstr(str + i, to_find));
    return (str);
}