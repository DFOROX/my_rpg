/*
** EPITECH PROJECT, 2019
** pause_init.c
** File description:
** display all pause items
*/

#include "pause.h"

void display_pause_button(ctr_t *ctr, button_t *pause_button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(ctr->window);

    sfRenderWindow_clear(ctr->window, sfBlack);
    sfRenderWindow_drawSprite(ctr->window, ctr->maps[ctr->m].spt, NULL);
    sfRenderWindow_drawSprite(ctr->window, ctr->player->spt, NULL);
    sfRenderWindow_drawSprite(ctr->window, ctr->obj[40].spt, NULL);
    for (int i = 0; i < NB_PAUSE_BUTTON; i++) {
        if (pause_button[i].pos3.x < mouse.x && pause_button[i].pos3.x + 7 * \
        CHAR_PAUSE_SIZE > mouse.x && pause_button[i].pos3.y < mouse.y && \
        pause_button[i].pos3.y + CHAR_PAUSE_SIZE > mouse.y) {
            sfText_setColor(pause_button[i].txt, \
            sfMouse_isButtonPressed(sfMouseLeft) ? pause_button[i].color[2] : \
            pause_button[i].color[1]);
        } else
            sfText_setColor(pause_button[i].txt, pause_button[i].color[0]);
        sfRenderWindow_drawText(ctr->window, pause_button[i].txt, NULL);
    }
    sfRenderWindow_display(ctr->window);
}
