/*
** EPITECH PROJECT, 2019
** player_lvl.c
** File description:
** set player lvl
*/

#include "../my.h"

void update_level(ctr_t *ctr)
{
    if (ctr->player->xp >= ctr->player->lvl * ctr->player->lvl * 20) {
        ctr->player->xp -= ctr->player->lvl * ctr->player->lvl * 20;
        ctr->player->lvl += 1;
        ctr->player->cpt_nb += 3;
    }
}
