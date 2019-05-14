/*
** EPITECH PROJECT, 2018
** my_memcpy.c
** File description:
** cpy byte per byte
*/


void *my_memcopy(void *dest, const void *src, unsigned long len)
{
    char *d = dest;
    const char *s = src;

    while (len--)
        *d++ = *s++;
    return (dest);
}

void my_memcpy(void *dest, void const *src, unsigned long n)
{
    unsigned char *csrc = (unsigned char *)src;
    unsigned char *cdest = (unsigned char *)dest;

    for (unsigned long i = 0; i < n; i++)
        cdest[i] = csrc[i];
}
