/*
** EPITECH PROJECT, 2019
** capital_pts.c
** File description:
** tarek
*/

#include "inventory.h"

void set_pos_button(ctr_t *ctr, stat_inventory_t **stats)
{
    for (int i = 0; i < 4; ++i) {
        if (ctr->player->cpt_nb > 0 && !my_strcmp((*stats)[i].str, "Life:")) {
            sfSprite_setPosition(ctr->obj[36].spt, (sfVector2f) \
            {((*stats)[i].pos3.x + 250), ((*stats)[i].pos3.y)});
            sfRenderWindow_drawSprite(ctr->window, ctr->obj[36].spt, NULL);
        } else if (ctr->player->cpt_nb > 0) {
            sfSprite_setPosition(ctr->obj[36].spt, (sfVector2f) \
            {((*stats)[i].pos3.x + 200), ((*stats)[i].pos3.y)});
            sfRenderWindow_drawSprite(ctr->window, ctr->obj[36].spt, NULL);
        }
    }
}

void set_pos_click(ctr_t *ctr, stat_inventory_t **stats)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    ctr->player->cpt_nb > 0) {
        while (sfMouse_isButtonPressed(sfMouseLeft));
        pos_click1(ctr, stats);
        pos_click2(ctr, stats);
        pos_click3(ctr, stats);
        pos_click4(ctr, stats);
    }
}
