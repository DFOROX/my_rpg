/*
** EPITECH PROJECT, 2018
** my_getnbr_base.c
** File description:
** get number in every base
*/

int compare_to_base(char const *base, char const c)
{
    for (int i = 0; base[i] != 0; i++)
        if (base[i] == c)
            return (1);
    return (0);
}

int get_base(char const *base, char const c)
{
    int i = 0;

    while (base[i] != 0 && base[i] != c)
        ++i;
    return (i);
}

int add_value(int value, char const *base, char const c, int count)
{
    if (value == 0)
        value = get_base(base, c);
    else
        value = (value * count) + get_base(base, c);
    return (value);
}

int my_getnbr_base(char const *str, char const *base)
{
    int i = 0;
    int count = -1;
    long my_value = 0;
    int sign = 1;

    while (base[++count] != 0);
    while (str[i] != 0 && (str[i] == 45 || str[i] == 43))
        if (str[i++] == 45)
            sign *= -1;
    while (str[i] != 0 && compare_to_base(base, str[i]) == 1) {
        if ((my_value > 2147483647 && sign == 1) || \
            (my_value > 2147483648 && sign == -1))
            return (0);
        my_value = add_value(my_value, base, str[i], count);
        ++i;
    }
    return (my_value * sign);
}
