/*
** EPITECH PROJECT, 2019
** anim_entities
** File description:
** anim_entities.c
*/

#include "tarek.h"

void init_rect(ctr_t *ctr)
{
    ctr->obj[15].rect.left = 50;
    ctr->obj[15].rect.top = 0;
    ctr->obj[15].rect.height = 132;
    ctr->obj[15].rect.width = 55;
    ctr->obj[16].rect.left = 0;
    ctr->obj[16].rect.top = 0;
    ctr->obj[16].rect.height = 192;
    ctr->obj[16].rect.width = 211;
    ctr->obj[15].clock = sfClock_create();
    ctr->obj[16].clock = sfClock_create();
    ctr->obj[44].rect.top = 0;
    ctr->obj[44].rect.height = 120;
    ctr->obj[44].rect.width = 190;
    ctr->obj[44].rect.left = 0;
    ctr->obj[44].clock = sfClock_create();
    ctr->obj[16].clock = sfClock_create();
    sfSprite_setScale(ctr->obj[17].spt, (sfVector2f){2, 2});
    sfSprite_setScale(ctr->obj[17].spt, (sfVector2f){2, 2});
    sfSprite_setScale(ctr->obj[15].spt, (sfVector2f){3, 3});
    sfSprite_setScale(ctr->obj[43].spt, (sfVector2f){2, 2});
}

void init_rect2(ctr_t *ctr)
{
    ctr->obj[17].rect.left = 0;
    ctr->obj[17].rect.top = 0;
    ctr->obj[17].rect.height = 120;
    ctr->obj[17].rect.width = 116;
    ctr->obj[18].rect.left = 0;
    ctr->obj[18].rect.top = 0;
    ctr->obj[18].rect.height = 186;
    ctr->obj[18].rect.width = 125;
    ctr->obj[19].rect.left = 0;
    ctr->obj[19].rect.top = 0;
    ctr->obj[19].rect.height = 146;
    ctr->obj[19].rect.width = 142;
    ctr->obj[17].clock = sfClock_create();
    ctr->obj[18].clock = sfClock_create();
    ctr->obj[19].clock = sfClock_create();
    sfSprite_setScale(ctr->obj[45].spt, (sfVector2f){2, 2});
}

void loop_anim_monster(ctr_t *ctr, int max, int index)
{
    ctr->obj[index].time = sfClock_getElapsedTime(ctr->obj[index].clock);
    ctr->obj[index].seconds = ctr->obj[index].time.microseconds / 1000000.0;
    if (ctr->obj[index].seconds > 0.2 && ctr->obj[index].rect.top == 0) {
        if (ctr->obj[index].rect.top == 0 && ctr->obj[index].rect.left >= max)
            ctr->obj[index].rect.left = 0;
        else if (ctr->obj[index].rect.top == 0)
            ctr->obj[index].rect.left += ctr->obj[index].rect.width;
        sfSprite_setTextureRect(ctr->obj[index].spt, ctr->obj[index].rect);
        sfClock_restart(ctr->obj[index].clock);
    }
}

void loop_anim_competencies(ctr_t *ctr, int index, int a, int max)
{
    ctr->obj[index].time = sfClock_getElapsedTime(ctr->obj[index].clock);
    ctr->obj[index].seconds = ctr->obj[index].time.microseconds / 100000.0;
    if (ctr->obj[index].seconds > 0.8 && ctr->obj[index].rect.top == 0 && a) {
        ctr->obj[index].rect.left += ctr->obj[index].rect.width;
        sfSprite_setTextureRect(ctr->obj[index].spt, ctr->obj[index].rect);
        sfClock_restart(ctr->obj[index].clock);
    }
    if (ctr->obj[index].seconds > 0.8 && ctr->obj[index].rect.top != 0) {
        if (ctr->obj[index].rect.left <= max)
            ctr->obj[index].rect.left += ctr->obj[index].rect.width;
        else if (ctr->obj[index].rect.left > max) {
            ctr->obj[index].rect.left = 0;
            ctr->obj[index].rect.top = 0;
        }
        sfSprite_setTextureRect(ctr->obj[index].spt, ctr->obj[index].rect);
        sfClock_restart(ctr->obj[index].clock);
    }
}

void set_pos_light(ctr_t *data, monster_t *m)
{
    if (m[0].pv > 0) {
        sfSprite_setPosition(data->obj[43].spt, (sfVector2f){3 * 275, 195});
        sfRenderWindow_drawSprite(data->window, data->obj[43].spt, NULL);
    }
    if (m[1].pv > 0) {
        sfSprite_setPosition(data->obj[43].spt, (sfVector2f){4 * 275, 195});
        sfRenderWindow_drawSprite(data->window, data->obj[43].spt, NULL);
    }
    if (m[2].pv > 0) {
        sfSprite_setPosition(data->obj[43].spt, (sfVector2f){5 * 275, 195});
        sfRenderWindow_drawSprite(data->window, data->obj[43].spt, NULL);
    }
}