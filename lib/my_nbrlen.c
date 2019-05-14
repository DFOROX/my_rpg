/*
** EPITECH PROJECT, 2018
** my_nbrlen.c
** File description:
** count lengh nbr
*/

int my_nbrlen(long nb)
{
    int val = nb < 0 ? 1 : 0;
    nb = nb < 0 ? nb * -1 : nb;

    for (; nb > 0; ++val, nb /= 10);
    return (val == 0 ? 1 : val);
}

int my_nbrlen_base(long nb, char *base)
{
    int val = nb < 0 ? 1 : 0;
    nb = nb < 0 ? nb * -1 : nb;
    int len = 0;

    for (int i = 0; base[i] != 0; i++, ++len);
    for (; nb > 0; ++val, nb /= len);
    return (val);
}
