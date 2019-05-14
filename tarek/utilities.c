/*
** EPITECH PROJECT, 2019
** utilities.c
** File description:
** tarek
*/

#include "tarek.h"

void set_pos_compt(ctr_t *data, int j)
{
    if (j == 0) {
        sfSprite_setPosition(data->obj[15].spt, (sfVector2f){3 * 270, 365});
        sfSprite_setPosition(data->obj[49].spt, (sfVector2f){3 * 260, 500});
    }
    if (j == 1) {
        sfSprite_setPosition(data->obj[15].spt, (sfVector2f){4 * 270, 365});
        sfSprite_setPosition(data->obj[49].spt, (sfVector2f){4 * 260, 500});
    }
    if (j == 2) {
        sfSprite_setPosition(data->obj[15].spt, (sfVector2f){5 * 270, 365});
        sfSprite_setPosition(data->obj[49].spt, (sfVector2f){5 * 260, 500});
    }
}

void init_vect_mstr(monster_t *monsters)
{
    monsters->mstr1.x = 3 * 250;
    monsters->mstr2.x = 4 * 250;
    monsters->mstr3.x = 5 * 250;
    monsters->mstr1.y = 500;
    monsters->mstr2.y = 500;
    monsters->mstr3.y = 500;
}

void print_spt(ctr_t *data, monster_t *monsters)
{
    for (int i = 0; i < 3; i++) {
        sfText_setString(data->obj[11].txt, my_itoa_static(monsters[i].pv));
        sfText_setPosition(data->obj[11].txt, (sfVector2f){1480, 850 + \
        (i * 60)});
        sfText_setString(data->obj[15].txt, monsters[i].name);
        sfText_setPosition(data->obj[15].txt, (sfVector2f){1360, 850 + \
        (i * 60)});
        if (monsters[i].pv > 0) {
            sfRenderWindow_drawText(data->window, data->obj[11].txt, NULL);
            sfRenderWindow_drawText(data->window, data->obj[15].txt, NULL);
        }
    }
}

void choose_cible2(ctr_t *data, monster_t *monsters, int i)
{
    if (i == 0 && monsters[0].pv > 0) {
        sfSprite_setPosition(data->obj[14].spt, (sfVector2f){1290, 850 + \
        (0 * 60)});
        display_anim(data, monsters, 1, 0);
    }
    if (i == 1 && monsters[1].pv > 0) {
        sfSprite_setPosition(data->obj[14].spt, (sfVector2f){1290, 850 + \
        (1 * 60)});
        display_anim(data, monsters, 1, 0);
    }
    if (i == 2 && monsters[2].pv > 2) {
        sfSprite_setPosition(data->obj[14].spt, (sfVector2f){1290, 850 + \
        (2 * 60)});
        display_anim(data, monsters, 1, 0);
    }
}
