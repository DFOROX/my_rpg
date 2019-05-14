/*
** EPITECH PROJECT, 2018
** my_strupcase.c
** File description:
** convert charac
*/

char *my_strupcase(char *str)
{
    for (char *tmp = str; *tmp != 0; tmp += 1) {
        if (*tmp > 96 && *tmp < 123)
            *tmp -= 32;
    }
    return (str);
}
