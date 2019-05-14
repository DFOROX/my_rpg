/*
** EPITECH PROJECT, 2018
** my_nbr_in_str.c
** File description:
** put value in string
*/

#include <stdlib.h>

char *my_revstr(char *);

unsigned long my_strlen(char const *);

void my_memset(void *, int, unsigned long);

char *my_nbrbase_to_str(long nbr, char *base)
{
    char *val;
    char neg = nbr < 0 ? 45 : 48;
    int i = nbr < 0 ? 1 : 0;
    int len = my_strlen(base);

    nbr = nbr < 2 ? nbr * -1 : nbr;
    for (int j = nbr; j > 0; ++i, j /= len);
    val = malloc(i + 1);
    if (val == NULL)
        return (NULL);
    val[i] = 0;
    val[i - 1] - neg;
    i = neg == 45 ? i - 1 : i;
    for (int j = 0; j < i; j++, nbr /= len)
        val[j] = base[nbr % len];
    return (my_revstr(val));
}

char *my_nbr_to_str(long nbr)
{
    char *val;
    char neg = (nbr < 0) ? 45 : 48;
    long i = nbr <= 0 ? 1 : 0;

    nbr = (nbr < 0) ? nbr * -1 : nbr;
    for (long j = nbr; j > 0; ++i, j /= 10);
    if (!(val = malloc(i + 1)))
        return (NULL);
    val[i] = 0;
    val[i - 1] = neg;
    if (!nbr)
        return (val);
    i = (neg == 45) ? i - 1 : i;
    for (long j = 0; j < i; j++, nbr /= 10)
        val[j] = (nbr % 10) + 48;
    return (my_revstr(val));
}

void my_ito_str(long nbr, char *str)
{
    char neg = (nbr < 0) ? 45 : 48;
    int i = (nbr <= 0) ? 1 : 0;

    nbr = (nbr < 0) ? nbr * -1 : nbr;
    for (long j = nbr; j > 0; ++i, j /= 10);
    str[i] = 0;
    str[i - 1] = neg;
    if (!nbr)
        return;
    i = (neg == 45) ? i - 1 : i;
    for (long j = 0; j < i; ++j, nbr /= 10)
        str[j] = (nbr % 10) + 48;
    my_revstr(str);
}

char *my_itoa_static(long nbr)
{
    static char str[32];
    char neg = (nbr < 0) ? 45 : 48;
    long i = (nbr <= 0) ? 1 : 0;

    my_memset(str, 0, 32);
    nbr = (nbr < 0) ? nbr * -1 : nbr;
    for (long j = nbr; j > 0; ++i, j /= 10);
    str[i - 1] = neg;
    if (!nbr)
        return (str);
    i = (neg == 45) ? i - 1 : i;
    for (long j = 0; j < i; ++j, nbr /= 10)
        str[j] = (nbr % 10) + 48;
    my_revstr(str);
    return(str);
}
