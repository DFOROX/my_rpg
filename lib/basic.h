/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib
*/

#ifndef BASIC_H_
#define BASIC_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/*  Basics Fonctions:                   */
// void my_putchar(char c);
// void my_putstr(char *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
// void my_putnbr(int nb);
// char *my_nbrstr(int nb);
char *my_strcatn(char *str1, char *str2);
int my_strcmpn(char const *str1, char const *str2);
//char *my_strcpy(char *str);
char **my_str_to_word_array(char *str, char *p);
// char **my_str_to_str_array(char *str, char *p);

#endif /* BASIC_H_ */
