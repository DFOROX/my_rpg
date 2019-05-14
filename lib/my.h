/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char bool;
enum {false, true};



/*  Basics Fonctions:                   */
void *my_malloc2(size_t byte, size_t size, size_t n);
void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
int my_getnbr(char *str);
void my_putnbr(int nb);
char *my_nbrstr(int nb);
char *my_strcatn(char *str1, char *str2);
bool my_strcmpn(char *str1, char *str2);
char *my_strcpy(char *str);
char **my_str_to_word_array(char *str, char *p);
char **my_str_to_str_array(char *str, char *p);
int my_printf(char *arg, ...);

#endif /* MY_H_ */
