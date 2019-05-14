/*
** EPITECH PROJECT, 2019
** pnj2
** File description:
** pnj2
*/

#include "tarek.h"

void inn(ctr_t *data)
{
    draw_text("You feel better", data);
    data->player->life = data->player->hp_max;
}
