/*
** EPITECH PROJECT, 2018
** my_strcapitalize.c
** File description:
** get all characts in string on Upcase
*/

char *my_strcapitalize(char *str)
{
    if (!*str)
        return (str);
    if (*str >= 'a' && *str <= 'z')
        str[0] -= 32;
    for (int i = 1; str[i]; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') && ((str[i - 1] >= 'a' && \
            str[i - 1] <= 'z') || (str[i - 1] >= '0' && str[i - 1] <= '9') \
            || (str[i - 1] >= 'A' && str[i - 1] <= 'Z')))
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (!(str[i - 1] >= 'a' && \
            str[i - 1] <= 'z') && !(str[i - 1] >= '0' && str[i - 1] <= '9') \
            && !(str[i - 1] >= 'A' && str[i - 1] <= 'Z')))
            str[i] -= 32;
    }
    return (str);
}
