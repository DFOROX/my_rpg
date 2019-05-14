/*
** EPITECH PROJECT, 2019
** set_tab_mstr
** File description:
** set tab
*/

#include "tarek.h"

void set_pos_tab4(monster_t *monsters, ctr_t *data, int index, int index2)
{
    if (monsters[0].pv > 0 && !my_strcmp(monsters[0].name, "mage")) {
        sfSprite_setPosition(data->obj[index2].spt, monsters->mstr1);
        sfRenderWindow_drawSprite(data->window, data->obj[index2].spt, NULL);
    } else if (monsters[0].pv > 0 && !my_strcmp(monsters[0].name, "soldat")) {
        sfSprite_setPosition(data->obj[index].spt, monsters->mstr1);
        sfRenderWindow_drawSprite(data->window, data->obj[index].spt, NULL); }
    if (monsters[1].pv > 0 && !my_strcmp(monsters[1].name, "mage")) {
        sfSprite_setPosition(data->obj[index2].spt, monsters->mstr2);
        sfRenderWindow_drawSprite(data->window, data->obj[index2].spt, NULL);
    } else if (monsters[1].pv > 0 && !my_strcmp(monsters[1].name, "soldat")) {
        sfSprite_setPosition(data->obj[index].spt, monsters->mstr2);
        sfRenderWindow_drawSprite(data->window, data->obj[index].spt, NULL); }
    if (monsters[2].pv > 0 && !my_strcmp(monsters[2].name, "mage")) {
        sfSprite_setPosition(data->obj[index2].spt, monsters->mstr3);
        sfRenderWindow_drawSprite(data->window, data->obj[index2].spt, NULL);
    } else if (monsters[2].pv > 0 && !my_strcmp(monsters[2].name, "soldat")) {
        sfSprite_setPosition(data->obj[index].spt, monsters->mstr3);
        sfRenderWindow_drawSprite(data->window, data->obj[index].spt, NULL);
    }
}

void set_pos_tab1(monster_t *monsters, ctr_t *data, int index, int index2)
{
    if (monsters[0].pv > 0 && !my_strcmp(monsters[0].name, "wisp")) {
        sfSprite_setPosition(data->obj[index2].spt, monsters->mstr1);
        sfRenderWindow_drawSprite(data->window, data->obj[index2].spt, NULL);
    } else if (monsters[0].pv > 0 && !my_strcmp(monsters[0].name, "rat")) {
        sfSprite_setPosition(data->obj[index].spt, monsters->mstr1);
        sfRenderWindow_drawSprite(data->window, data->obj[index].spt, NULL); }
    if (monsters[1].pv > 0 && !my_strcmp(monsters[1].name, "wisp")) {
        sfSprite_setPosition(data->obj[index2].spt, monsters->mstr2);
        sfRenderWindow_drawSprite(data->window, data->obj[index2].spt, NULL);
    } else if (monsters[1].pv > 0 && !my_strcmp(monsters[1].name, "rat")) {
        sfSprite_setPosition(data->obj[index].spt, monsters->mstr2);
        sfRenderWindow_drawSprite(data->window, data->obj[index].spt, NULL); }
    if (monsters[2].pv > 0 && !my_strcmp(monsters[2].name, "wisp")) {
        sfSprite_setPosition(data->obj[index2].spt, monsters->mstr3);
        sfRenderWindow_drawSprite(data->window, data->obj[index2].spt, NULL);
    } else if (monsters[2].pv > 0 && !my_strcmp(monsters[2].name, "rat")) {
        sfSprite_setPosition(data->obj[index].spt, monsters->mstr3);
        sfRenderWindow_drawSprite(data->window, data->obj[index].spt, NULL);
    }
}

void set_pos_tab3(monster_t *monsters, ctr_t *data, int index, int index2)
{
    if (monsters[0].pv > 0 && !my_strcmp(monsters[0].name, "chamane")) {
        sfSprite_setPosition(data->obj[index2].spt, monsters->mstr1);
        sfRenderWindow_drawSprite(data->window, data->obj[index2].spt, NULL);
    } else if (monsters[0].pv > 0 && !my_strcmp(monsters[0].name, "gobelin")) {
        sfSprite_setPosition(data->obj[index].spt, monsters->mstr1);
        sfRenderWindow_drawSprite(data->window, data->obj[index].spt, NULL); }
    if (monsters[1].pv > 0 && !my_strcmp(monsters[1].name, "chamane")) {
        sfSprite_setPosition(data->obj[index2].spt, monsters->mstr2);
        sfRenderWindow_drawSprite(data->window, data->obj[index2].spt, NULL);
    } else if (monsters[1].pv > 0 && !my_strcmp(monsters[1].name, "gobelin")) {
        sfSprite_setPosition(data->obj[index].spt, monsters->mstr2);
        sfRenderWindow_drawSprite(data->window, data->obj[index].spt, NULL); }
    if (monsters[2].pv > 0 && !my_strcmp(monsters[2].name, "chamane")) {
        sfSprite_setPosition(data->obj[index2].spt, monsters->mstr3);
        sfRenderWindow_drawSprite(data->window, data->obj[index2].spt, NULL);
    } else if (monsters[2].pv > 0 && !my_strcmp(monsters[2].name, "gobelin")) {
        sfSprite_setPosition(data->obj[index].spt, monsters->mstr3);
        sfRenderWindow_drawSprite(data->window, data->obj[index].spt, NULL);
    }
}

void set_monster_state(ctr_t *data, monster_t *monsters)
{
    if (data->state == 1) {
        loop_anim_monster(data, 158, 47);
        loop_anim_monster(data, 101, 50);
        set_pos_tab1(monsters, data, 47, 50);
    }
    if (data->state == 3) {
        loop_anim_monster(data, 284, 19);
        loop_anim_monster(data, 633, 16);
        set_pos_tab3(monsters, data, 19, 16);
    }
    if (data->state == 4) {
        loop_anim_monster(data, 696, 17);
        loop_anim_monster(data, 375, 18);
        loop_anim_monster(data, 207, 45);
        if (monsters[2].pv > 0 && !my_strcmp(monsters[2].name, "boss")) {
            sfSprite_setPosition(data->obj[45].spt, monsters->mstr3);
            sfRenderWindow_drawSprite(data->window, data->obj[45].spt, NULL);
        }
        set_pos_tab4(monsters, data, 17, 18);
    }
}