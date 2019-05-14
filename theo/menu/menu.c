/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** display menu state
*/

#include "menu.h"

void main_menu(ctr_t *ctr)
{
    button_t button[BUT_S] = {0};
    button_t *but = (button_t *)button;
    menu_t menu = {0, ctr->obj[6].music, 0, NULL, {0}, NULL};
    button_t *save_button = create_save_button(ctr, &menu);

    fill_button_array(ctr, &but);
    menu_init_how_play(ctr, &menu);
    init_sound_button(ctr);
    sfMusic_setLoop(ctr->obj[4].music, sfTrue);
    sfMusic_play(ctr->obj[4].music);
    while (ctr->game_state == 1 && sfRenderWindow_isOpen(ctr->window)) {
        sf_poll_event(ctr, &but, &menu, save_button);
        sfRenderWindow_clear(ctr->window, sfBlack);
        sfRenderWindow_drawSprite(ctr->window, ctr->obj[1].spt, NULL);
        menu_button(ctr, &but, &menu, save_button);
        sfRenderWindow_drawText(ctr->window, button[BUT_S_L].txt, NULL);
        sfRenderWindow_display(ctr->window);
    }
    sfMusic_stop(ctr->obj[4].music);
    clean_menu(&but, &menu, save_button);
}
