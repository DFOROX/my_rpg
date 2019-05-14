/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** get number in string
*/

int my_getnbr(char const *str)
{
    int i = 0;
    long my_value = 0;
    int sign = 1;

    if (!str)
        return (0);
    while (str[i] != 0 && (str[i] == 45 || str[i] == 43))
        if (str[i++] == 45)
            sign *= -1;
    while (str[i] != 0 && (str[i] > 47 && str[i] < 58) ) {
        if ((my_value > 2147483647 && sign == 1) || \
        (my_value > 2147483648 && sign == -1))
            return (0);
            my_value = (my_value * 10) + (str[i] - 48);
        ++i;
    }
    return (my_value * sign);
}
