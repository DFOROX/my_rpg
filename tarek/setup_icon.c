/*
** EPITECH PROJECT, 2019
** setup icone
** File description:
** setup_icone.c
*/

#include "tarek.h"

void init_pos_icone(ctr_t *data)
{
    data->obj[13].pos_icon[0].x = 560;
    data->obj[13].pos_icon[0].y = 898;
    data->obj[13].pos_icon[1].x = 697;
    data->obj[13].pos_icon[1].y = 841;
    data->obj[13].pos_icon[2].x = 841;
    data->obj[13].pos_icon[2].y = 841;
    data->obj[13].pos_icon[3].x = 990;
    data->obj[13].pos_icon[3].y = 843;
    data->obj[13].pos_icon[4].x = 696;
    data->obj[13].pos_icon[4].y = 947;
    data->obj[13].pos_icon[5].x = 841;
    data->obj[13].pos_icon[5].y = 946;
    data->obj[13].pos_icon[6].x = 987;
    data->obj[13].pos_icon[6].y = 949;
}

void select_comp(ctr_t *data, int p[2], monster_t *monsters)
{
    if (!p[0])
        sfSprite_setPosition(data->obj[13].spt, data->obj[13].pos_icon[0]);
    if (p[0] == 1 && !p[1])
        sfSprite_setPosition(data->obj[13].spt, data->obj[13].pos_icon[1]);
    if (p[0] == 2 && !p[1])
        sfSprite_setPosition(data->obj[13].spt, data->obj[13].pos_icon[2]);
    if (p[0] == 3 && !p[1])
        sfSprite_setPosition(data->obj[13].spt, data->obj[13].pos_icon[3]);
    if (p[0] == 1 && p[1] == 1)
        sfSprite_setPosition(data->obj[13].spt, data->obj[13].pos_icon[4]);
    if (p[0] == 2 && p[1] == 1)
        sfSprite_setPosition(data->obj[13].spt, data->obj[13].pos_icon[5]);
    if (p[0] == 3 && p[1] == 1)
        sfSprite_setPosition(data->obj[13].spt, data->obj[13].pos_icon[6]);
    display(data, monsters);
}

void init_rect3(ctr_t *ctr)
{
    ctr->obj[43].rect.left = 0;
    ctr->obj[43].rect.top = 0;
    ctr->obj[43].rect.height = 250;
    ctr->obj[43].rect.width = 64;
    ctr->obj[45].rect.left = 0;
    ctr->obj[45].rect.top = 0;
    ctr->obj[45].rect.height = 105;
    ctr->obj[45].rect.width = 69;
    ctr->obj[47].rect.left = 0;
    ctr->obj[47].rect.top = 0;
    ctr->obj[47].rect.height = 47;
    ctr->obj[47].rect.width = 79;
    ctr->obj[43].clock = sfClock_create();
    ctr->obj[45].clock = sfClock_create();
    ctr->obj[47].clock = sfClock_create();
    sfSprite_setScale(ctr->obj[47].spt, (sfVector2f){2, 2});
}

void init_rect4(ctr_t *ctr)
{
    ctr->obj[48].rect.top = 0;
    ctr->obj[48].rect.height = 120;
    ctr->obj[48].rect.width = 190;
    ctr->obj[48].rect.left = 0;
    ctr->obj[50].rect.top = 0;
    ctr->obj[50].rect.height = 118;
    ctr->obj[50].rect.width = 101;
    ctr->obj[50].rect.left = 0;
    ctr->obj[49].rect.height = 100;
    ctr->obj[49].rect.width = 120;
    ctr->obj[49].rect.left = 0;
    ctr->obj[49].clock = sfClock_create();
    ctr->obj[50].clock = sfClock_create();
    ctr->obj[48].clock = sfClock_create();
}

void set_pos_buff(ctr_t *data)
{
    if (data->inv_it[2]->type == 1) {
        sfSprite_setPosition(data->obj[48].spt, (sfVector2f) \
        {data->obj[13].pos_icon[0].x - 45, data->obj[13].pos_icon[0].y});
        sfRenderWindow_drawSprite(data->window, data->obj[48].spt, NULL);
    }
    sfSprite_setPosition(data->obj[48].spt, (sfVector2f) \
    {data->obj[13].pos_icon[4].x - 45, data->obj[13].pos_icon[4].y});
    sfRenderWindow_drawSprite(data->window, data->obj[48].spt, NULL);
    sfSprite_setPosition(data->obj[48].spt, (sfVector2f) \
    {data->obj[13].pos_icon[6].x - 45, data->obj[13].pos_icon[6].y});
    sfRenderWindow_drawSprite(data->window, data->obj[48].spt, NULL);
}