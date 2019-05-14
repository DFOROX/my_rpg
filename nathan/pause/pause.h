/*
** EPITECH PROJECT, 2018
** pause.h
** File description:
** helps for user
*/

#ifndef _PAUSEH_
#define _PAUSEH_

#include "../my.h"
#include "../../theo/menu/menu.h"

#define CHAR_PAUSE_SIZE 42
#define NB_PAUSE_BUTTON 4

int button_event_pause(ctr_t *ctr, button_t *pause_button);
void close_event_pause(ctr_t *ctr);
void display_pause_button(ctr_t *ctr, button_t *pause_button);
void destroy_pause_button(button_t *pause_button);
button_t *create_pause_button(ctr_t *ctr);


#endif /* !_PAUSEH_ */
