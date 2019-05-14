/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** my_str_isalpha.c
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (!(str[i] > 64 && str[i] < 91) && !(str[i] > 96 && str[i] < 123))
            return (0);
    return (1);
}
