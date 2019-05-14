/*
** EPITECH PROJECT, 2019
** manage_anim_mstr.c
** File description:
** manage animation of monsters
*/

#include "tarek.h"

void manage_anim_mstr(ctr_t *data)
{
    loop_anim_competencies(data, 43, 1, 0);
    loop_anim_competencies(data, 15, 1, 0);
    loop_anim_competencies(data, 44, 1, 0);
    loop_anim_competencies(data, 48, 1, 0);
    loop_anim_competencies(data, 49, 1, 0);
    loop_anim_competencies(data, 16, 0, 580);
    loop_anim_competencies(data, 17, 0, 464);
    loop_anim_competencies(data, 18, 0, 250);
    loop_anim_competencies(data, 19, 0, 284);
    loop_anim_competencies(data, 45, 0, 207);
    loop_anim_competencies(data, 47, 0, 79);
    loop_anim_competencies(data, 50, 0, 303);
}

void draw_anim(ctr_t *data, monster_t *monsters, int a, int b)
{
    if (a == 1)
        sfRenderWindow_drawSprite(data->window, data->obj[14].spt, NULL);
    if (a == 2)
        sfRenderWindow_drawSprite(data->window, data->obj[15].spt, NULL);
    if (b == 1)
        set_pos_light(data, monsters);
    if (b == 2)
        sfRenderWindow_drawSprite(data->window, data->obj[44].spt, NULL);
    if (b == 3)
        set_pos_buff(data);
    if (a == 4)
        sfRenderWindow_drawSprite(data->window, data->obj[49].spt, NULL);
}