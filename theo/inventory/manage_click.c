/*
** EPITECH PROJECT, 2019
** manage_click.c
** File description:
** tarek
*/

#include "inventory.h"

void pos_click1(ctr_t *ctr, stat_inventory_t **stats)
{
    if (sfMouse_getPosition((sfWindow *)ctr->window).x > (sfVector2f){( \
        (*stats)[0].pos3.x + 250), ((*stats)[0].pos3.y)}.x && \
        sfMouse_getPosition((sfWindow *)ctr->window).x < (sfVector2f){( \
        (*stats)[0].pos3.x + 250), ((*stats)[0].pos3.y)}.x + 20 && \
        sfMouse_getPosition((sfWindow *)ctr->window).y > (sfVector2f){( \
        (*stats)[0].pos3.x + 250), ((*stats)[0].pos3.y)}.y  && \
        sfMouse_getPosition((sfWindow *)ctr->window).y < (sfVector2f){( \
        (*stats)[0].pos3.x + 250), ((*stats)[0].pos3.y)}.y + 20) {
            ctr->player->hp_max += 10;
            ctr->player->life = ctr->player->hp_max;
            ctr->player->cpt_nb --;
    }
}

void pos_click2(ctr_t *ctr, stat_inventory_t **stats)
{
    if (sfMouse_getPosition((sfWindow *)ctr->window).x > (sfVector2f){( \
        (*stats)[2].pos3.x + 200), ((*stats)[2].pos3.y)}.x && \
        sfMouse_getPosition((sfWindow *)ctr->window).x < (sfVector2f){( \
        (*stats)[2].pos3.x + 200), ((*stats)[2].pos3.y)}.x + 20 && \
        sfMouse_getPosition((sfWindow *)ctr->window).y > (sfVector2f){( \
        (*stats)[2].pos3.x + 200), ((*stats)[2].pos3.y)}.y  && \
        sfMouse_getPosition((sfWindow *)ctr->window).y < (sfVector2f){( \
        (*stats)[2].pos3.x + 200), ((*stats)[2].pos3.y)}.y + 20) {
            ctr->player->stat[0] += 1;
            ctr->player->cpt_nb --;
    }
}

void pos_click3(ctr_t *ctr, stat_inventory_t **stats)
{
    if (sfMouse_getPosition((sfWindow *)ctr->window).x > (sfVector2f){( \
        (*stats)[3].pos3.x + 200), ((*stats)[3].pos3.y)}.x && \
        sfMouse_getPosition((sfWindow *)ctr->window).x < (sfVector2f){( \
        (*stats)[3].pos3.x + 200), ((*stats)[3].pos3.y)}.x + 20 && \
        sfMouse_getPosition((sfWindow *)ctr->window).y > (sfVector2f){( \
        (*stats)[3].pos3.x + 200), ((*stats)[3].pos3.y)}.y  && \
        sfMouse_getPosition((sfWindow *)ctr->window).y < (sfVector2f){( \
        (*stats)[3].pos3.x + 200), ((*stats)[3].pos3.y)}.y + 20) {
            if (ctr->player->speed > 3)
                ctr->player->speed -= 3;
            ctr->player->cpt_nb --;
    }
}

void pos_click4(ctr_t *ctr, stat_inventory_t **stats)
{
    if (sfMouse_getPosition((sfWindow *)ctr->window).x > (sfVector2f){( \
        (*stats)[1].pos3.x + 200), ((*stats)[1].pos3.y)}.x && \
        sfMouse_getPosition((sfWindow *)ctr->window).x < (sfVector2f){( \
        (*stats)[1].pos3.x + 200), ((*stats)[1].pos3.y)}.x + 20 && \
        sfMouse_getPosition((sfWindow *)ctr->window).y > (sfVector2f){( \
        (*stats)[1].pos3.x + 200), ((*stats)[1].pos3.y)}.y  && \
        sfMouse_getPosition((sfWindow *)ctr->window).y < (sfVector2f){( \
        (*stats)[1].pos3.x + 200), ((*stats)[1].pos3.y)}.y + 20) {
            ctr->player->stat[1] += 1;
            ctr->player->cpt_nb --;
    }
}
