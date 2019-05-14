/*
** EPITECH PROJECT, 2019
** fight_event.c
** File description:
** manage event
*/

#include "tarek.h"

void poll_event_manager(ctr_t *ctr, int *inventory_state)
{
    while (sfRenderWindow_pollEvent(ctr->window, &ctr->event)) {
        if (ctr->event.type == sfEvtClosed)
            sfRenderWindow_close(ctr->window);
        while (sfKeyboard_isKeyPressed(sfKeyI))
            *inventory_state = 1;
    }
}
