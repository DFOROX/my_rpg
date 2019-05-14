/*
** EPITECH PROJECT, 2019
** menu_event.c
** File description:
** loop menu event manager
*/

#include "menu.h"

void sf_poll_event(ctr_t *ctr, button_t **button, menu_t *menu, \
button_t *save_button)
{
    while (sfRenderWindow_pollEvent(ctr->window, &ctr->event)) {
        if (ctr->event.type == sfEvtClosed) {
            sfRenderWindow_close(ctr->window);
            return;
        } else if (ctr->event.key.code == sfKeyEscape) {
            for (int i = 1; i != BUT_S - 2; ++i)
                (*button)[i].state = 1;
            menu->me_st = 0;
        }
        if (sfMouse_isButtonPressed(sfMouseLeft))
            menu_mouse_event(ctr, button, menu, save_button);
    }
}
