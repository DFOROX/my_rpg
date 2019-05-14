/*
** EPITECH PROJECT, 2018
** my_memset.c
** File description:
** set byte per byte
*/

void my_memset(void *dest, int c, unsigned long n)
{
    unsigned char csrc = (unsigned char )c;
    unsigned char *cdest = (unsigned char *)dest;

    for (unsigned long i = 0; i < n; i++)
        cdest[i] = csrc;
}
