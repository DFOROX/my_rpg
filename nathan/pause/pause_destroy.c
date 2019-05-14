/*
** EPITECH PROJECT, 2019
** pause_init.c
** File description:
** destroy all created buttons in pause
*/

#include "pause.h"

void destroy_pause_button(button_t *pause_button)
{
    for (int i = 0; i < NB_PAUSE_BUTTON; i++)
        sfText_destroy(pause_button[i].txt);
    free(pause_button);
}
