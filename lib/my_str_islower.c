/*
** EPITECH PROJECT, 2018
** my_str_islower.c
** File description:
** my_str_islower.c
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (!(str[i] > 96 && str[i] < 123))
            return (0);
    return (1);
}
