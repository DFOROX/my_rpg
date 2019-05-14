/*
** EPITECH PROJECT, 2018
** my_str_isprintable.c
** File description:
** my_str_isprintable.c
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] < 32 || str[i] > 126)
            return (0);
    return (1);
}
