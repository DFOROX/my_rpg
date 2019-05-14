/*
** EPITECH PROJECT, 2019
** pause_loop.c
** File description:
** loop for pause menu
*/

#include "pause.h"

void loop_pause(ctr_t *ctr)
{
    button_t *pause_button = NULL;
    int loop_test = 1;

    if (!sfKeyboard_isKeyPressed(sfKeyEscape))
        return;
    pause_button = create_pause_button(ctr);
    sfSprite_setPosition(ctr->obj[40].spt, (sfVector2f) {SIZE_X / 2 - \
    sfTexture_getSize(ctr->obj[40].texture).x / 2, 150});
    display_pause_button(ctr, pause_button);
    while (sfKeyboard_isKeyPressed(sfKeyEscape))
        close_event_pause(ctr);
    while (loop_test == 1 && sfRenderWindow_isOpen(ctr->window) && \
    ctr->game_state != 1 && !button_event_pause(ctr, pause_button)) {
        display_pause_button(ctr, pause_button);
        while (sfKeyboard_isKeyPressed(sfKeyEscape))
            loop_test = 0;
        close_event_pause(ctr);
    }
    destroy_pause_button(pause_button);
}
