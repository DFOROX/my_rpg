/*
** EPITECH PROJECT, 2019
** trader_mouse_unclick_inv_to_sell.c
** File description:
** manage unclick mouse event
*/

#include "trader.h"

void trader_mouse_unclick_inv_to_sell(ctr_t *ctr, trader_t *trad)
{
    sfSprite_destroy(trad->inv_it[trad->drag_inv].spt);
    ctr->player->gold += trad->inv_it[trad->drag_inv].price;
    ctr->inv_it[trad->drag_inv] = NULL;
    trad->inv_it[trad->drag_inv].spt = NULL;
    sfText_setString(trad->trader_msg[GOLD_MSG_POS].txt, \
    my_itoa_static(ctr->player->gold));
}
