/*
** EPITECH PROJECT, 2019
** menu_button.c
** File description:
** manage buttons
*/

#include "menu.h"

void color_button_state2_bis(button_t *but, menu_t *me)
{
    if (me->me_st == 2) {
        sfText_setColor(but[1].txt, but[1].color[0]);
        sfText_setColor(but[2].txt, but[2].color[2]);
        sfText_setColor(but[3].txt, but[3].color[0]);
        but[1].state = 0;
        but[3].state = 0;
    }
    if (me->me_st == 3) {
        sfText_setColor(but[1].txt, but[1].color[0]);
        sfText_setColor(but[2].txt, but[2].color[0]);
        sfText_setColor(but[3].txt, but[3].color[2]);
        but[1].state = 0;
        but[2].state = 0;
    }
}

void color_button_state2(button_t *but, menu_t *me, int i)
{
    if (me->me_st == 1) {
        sfText_setColor(but[1].txt, but[1].color[2]);
        sfText_setColor(but[2].txt, but[2].color[0]);
        sfText_setColor(but[3].txt, but[3].color[0]);
        but[2].state = 0;
        but[3].state = 0;
    }
    color_button_state2_bis(but, me);
    but[i].state = 2;
}

void color_button(button_t *but, menu_t *me, sfVector2i pos, int i)
{
    if ((i == 1 && me->me_st == 1) || (i == 2 && me->me_st == 2) || (i == 3 && \
    me->me_st == 3)) {
        if (but[i].state != 2)
            color_button_state2(but, me, i);
    } else if (but[i].pos1.x < pos.x && but[i].pos2.x > pos.x && \
    but[i].pos1.y < pos.y && but[i].pos2.y > pos.y) {
        if (but[i].state == 0) {
            sfText_setColor(but[i].txt, but[i].color[1]);
            but[i].state = 1;
            sfMusic_play(me->music);
        }
    } else {
        if (but[i].state != 0) {
            sfText_setColor(but[i].txt, but[i].color[0]);
            but[i].state = 0;
        }
    }
}

void color_save_button(button_t *but, menu_t *me, sfVector2i pos)
{
    if (but->pos1.x < pos.x && but->pos2.x > pos.x && \
    but->pos1.y < pos.y && but->pos2.y > pos.y) {
        if (but->state == 0) {
            sfText_setColor(but->txt, but->color[2]);
            but->state = 1;
            sfMusic_play(me->music);
        }
    } else {
        if (but->state == 1) {
            sfText_setColor(but->txt, but->color[1]);
            but->state = 0;
        }
    }
}

void menu_button(ctr_t *ctr, button_t **button, menu_t *menu, \
button_t *save_button)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(ctr->window);

    for (int i = 0; i != BUT_S_L; ++i) {
        color_button(*button, menu, pos, i);
        sfRenderWindow_drawText(ctr->window, (*button)[i].txt, NULL);
    }
    if (menu->me_st == 1 && menu->nb_save)
        for (int i = 0; i != menu->nb_save; ++i) {
            color_save_button(save_button + i, menu, pos);
            sfRenderWindow_drawText(ctr->window, save_button[i].txt, NULL);
        }
    else if (menu->me_st == 1)
        sfRenderWindow_drawText(ctr->window, save_button->txt, NULL);
    if (menu->me_st == 2)
        sfRenderWindow_drawSprite(ctr->window, ctr->obj[8].spt, NULL);
    if (menu->me_st == 3)
        sfRenderWindow_drawText(ctr->window, menu->htp_txt, NULL);
}
