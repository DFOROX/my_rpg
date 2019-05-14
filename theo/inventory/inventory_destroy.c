/*
** EPITECH PROJECT, 2019
** inventory_destroy.c
** File description:
** destroy all inventory items
*/

#include "inventory.h"

void inventory_destroy(stat_inventory_t **stats, \
inventory_t *inventory)
{
    for (int i = 0; i != STAT_FIX; ++i)
        sfText_destroy((*stats)[i].txt);
    for (int i = STAT_FIX; i != TEXT_NB; ++i) {
        sfText_destroy((*stats)[i].txt);
    }
    sfText_destroy(inventory->warning_txt);
    sfText_destroy(inventory->item_lore_txt);
    for (int i = 0; i != NB_INV; ++i) {
        if (!inventory->inv_it[i].spt)
            continue;
        sfSprite_destroy(inventory->inv_it[i].spt);
    }
}
