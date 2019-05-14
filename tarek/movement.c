/*
** EPITECH PROJECT, 2019
** movement.c
** File description:
** tarek
*/

#include "tarek.h"

void change_map3(ctr_t *ctr)
{
    if (ctr->m == 4 && ctr->player->pos.y >= SIZE_Y - 10 && \
    ctr->maps[4].pos.x >= -1370) {
        ctr->m = 2;
        ctr->maps[2].pos.x = -1320;
        ctr->maps[2].pos.y = 0;
        ctr->player->pos.x = SIZE_X / 2;
        ctr->player->pos.y = 300;
    }
}

void change_map2(ctr_t *ctr)
{
    if (ctr->m == 2 && ctr->player->pos.x <= 0 && ctr->maps[2].pos.x <= 0 \
    && ctr->maps[2].pos.y <= -950 && ctr->maps[2].pos.y >= -1150) {
        ctr->m = 3;
        ctr->maps[3].pos.x = -2561;
        ctr->maps[3].pos.y = -783;
        ctr->player->pos.x = SIZE_X - 150;
        ctr->player->pos.y = 540;
    }
    if (ctr->m == 3 && ctr->maps[3].pos.x <= -2500 && \
    ctr->player->pos.x >= SIZE_X - 20 && ctr->maps[3].pos.y <= -700 && \
    ctr->maps[3].pos.y >= -900) {
        ctr->m = 2;
        ctr->maps[2].pos.x = 0;
        ctr->maps[2].pos.y = -1050;
        ctr->player->pos.x = 20;
        ctr->player->pos.y = 540;
    }
}

void change_map(ctr_t *ctr)
{
    if (ctr->m == 1 && ctr->maps[1].pos.y <= 1 && ctr->player->pos.y <= 1 && \
    ctr->maps[1].pos.x <= -1100 && ctr->maps[1].pos.x >= -1300) {
        ctr->m = 2;
        ctr->maps[2].pos.x = -1320;
        ctr->maps[2].pos.y = -2120;
        ctr->player->pos.x = SIZE_X / 2;
        ctr->player->pos.y = SIZE_Y - 20;
    }
    if (ctr->m == 2 && ctr->player->pos.y >= SIZE_Y - 10 && \
    ctr->maps[2].pos.x <= -1270 && ctr->maps[2].pos.x >= -1370) {
        ctr->m = 1;
        ctr->maps[1].pos.x = -1200;
        ctr->maps[1].pos.y = 0;
        ctr->player->pos.x = SIZE_X / 2;
        ctr->player->pos.y = 40;
    }
    change_map2(ctr);
    change_map3(ctr);
    ctr->state = ctr->m;
}

void loop_anim_player(ctr_t *play)
{
    play->player->time = sfClock_getElapsedTime(play->player->clock);
    play->player->seconds = play->player->time.microseconds / 100000.0;
    if (play->player->seconds > 1.2) {
        if (play->player->rect.left >= 144) {
            play->player->rect.left = 0;
        } else
            play->player->rect.left += 48;
        sfSprite_setPosition(play->player->spt, play->player->pos);
        sfClock_restart(play->player->clock);
    }
}

void spawn_fight(ctr_t *var)
{
    int a = rand()%500;

    if (!a && var->state != 2)
        fight(var);
}
