/*
** EPITECH PROJECT, 2019
** trader_destroy.c
** File description:
** destroy all trader items
*/

#include "trader.h"

void trader_destroy(trader_t *trad)
{
    for (int i = 0; i != NB_INV; ++i) {
        if (!trad->inv_it[i].spt)
            continue;
        sfSprite_destroy(trad->inv_it[i].spt);
    }
    for (int i = 0; i != NB_ITEM; ++i) {
        if (!trad->sel_it[i].spt)
            continue;
        sfSprite_destroy(trad->sel_it[i].spt);
    }
    sfSprite_destroy(trad->sell_drag_item.spt);
    for (int i = 0; i != NB_TRADER_MESSAGE; ++i)
        sfText_destroy(trad->trader_msg[i].txt);
    sfText_destroy(trad->warning_txt);
    sfText_destroy(trad->item_lore_txt);
}
