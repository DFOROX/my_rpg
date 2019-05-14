/*
** EPITECH PROJECT, 2018
** my_strlowcase.c
** File description:
** put char in str in lowcase
*/

char *my_strlowcase(char *str)
{
    for (char *tmp = str; *tmp != 0; tmp += 1)
        if (*tmp > 64 && *tmp < 91)
            *tmp += 32;
    return (str);
}
