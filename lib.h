/*
** EPITECH PROJECT, 2019
** lib.h
** File description:
** library prototype
*/

#ifndef LIB_H_
#define LIB_H_

#include "my.h"
#include "struct.h"

int my_getnbr(char const *);
char *my_convert_vase(char const *, char const *, char const *);
int my_getnbr_base(char const *, char const *);
void my_memcpy(void *, void const *, unsigned long);
void *my_memcopy(void *, const void *, unsigned long);
void my_memset(void *, int, unsigned long);
int my_nbrlen(long);
int my_nbrlen_base(long, char *);
char *my_nbr_to_str(long);
void my_ito_str(long, char *);
char *my_itoa_static(long);
char *my_nbrbase_to_str(long, char *);
int my_put_nbr(int);
int my_putnbr_base(int, char const *);
char *my_revstr(char *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
char *my_strdup(char const *);
unsigned long my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, unsigned long);
int my_strncmp(char const *, char const *, unsigned long);
char *my_strncpy(char *, char const *, unsigned long);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);

#endif
