/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** count string lenght
*/

unsigned long my_strlen(char const *str)
{
    unsigned long i = -1;

    if (!str)
        return (0);
    while (str[++i] != 0);
    return (i);
}
