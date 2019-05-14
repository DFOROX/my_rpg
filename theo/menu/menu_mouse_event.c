/*
** EPITECH PROJECT, 2019
** mouse_event.c
** File description:
** mouse event manage
*/

#include "menu.h"

void apply_click(ctr_t *ctr, int i, menu_t *menu)
{
    if (i == 0) {
        load_ctr(ctr, PATH_DEFAULT);
        ctr->game_state = 2;
        menu->me_st = 0;
    } else if (i == 1)
        menu->me_st = 1;
    if (i == 2)
        menu->me_st = 2;
    if (i == 3)
        menu->me_st = 3;
    else if (i == 4) {
        ctr->game_state = -1;
        menu->me_st = 3;
    }
    sfMusic_play(ctr->obj[5].music);
}

void mouse_event_save(ctr_t *ctr, menu_t *menu, button_t *save_button, \
sfVector2i pos)
{
    static char path[256] = PATH_SAVE;

    for (int i = 0; i != menu->nb_save; ++i) {
        if (pos.x > save_button->pos1.x && pos.x < save_button->pos2.x && \
        save_button[i].pos1.y < pos.y && save_button[i].pos2.y > pos.y) {
            my_strcat(path, save_button[i].str);
            ctr->game_state = 2;
            sfMusic_play(ctr->obj[5].music);
            load_ctr(ctr, path);
            break;
        }
    }
}

void mouse_event_sound(ctr_t *ctr, sfVector2i pos)
{
    if (pos.x > 893 && pos.x < 1028 && pos.y > 488 && pos.y < 593) {
        if (ctr->obj[8].rect.left == 0) {
            ctr->obj[8].rect.left = 136;
            set_volume_off(ctr);
        }
        else if (ctr->obj[8].rect.left == 136) {
            ctr->obj[8].rect.left = 0;
            set_volume_on(ctr);
        }
        sfMusic_play(ctr->obj[5].music);
        sfSprite_setTextureRect(ctr->obj[8].spt, ctr->obj[8].rect);
    }
}

void menu_mouse_event(ctr_t *ctr, button_t **button, menu_t *menu, \
button_t *save_button)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(ctr->window);

    for (int i = 0; i != BUT_S_L; ++i) {
        if (pos.x > (*button)[i].pos1.x && pos.x < (*button)[i].pos2.x \
        && (*button)[i].pos1.y < pos.y && (*button)[i].pos2.y > pos.y) {
            apply_click(ctr, i, menu);
            sfMusic_play(ctr->obj[5].music);
            break;
        }
    }
    if (menu->me_st == 1)
        mouse_event_save(ctr, menu, save_button, pos);
    if (menu->me_st == 2)
        mouse_event_sound(ctr, pos);
}
