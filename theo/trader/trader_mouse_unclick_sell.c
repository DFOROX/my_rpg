/*
** EPITECH PROJECT, 2019
** trader_mouse_unclick_sell.c
** File description:
** manage mouse unclick event
*/

#include "trader.h"

void trader_drop_sell_in_inv(ctr_t *ctr, trader_t *trad, int i)
{
    trad->inv_it[i].spt = sfSprite_create();
    trad->inv_it[i].name = ctr->items[trad->drag_sell].name;
    sfSprite_setTexture(trad->inv_it[i].spt, \
    ctr->items[trad->drag_sell].text, sfTrue);
    trad->inv_it[i].pos = \
    (sfVector2f){trad->item_pos[i].x, trad->item_pos[i].y};
    ctr->inv_it[i] = &ctr->items[trad->drag_sell];
    trad->inv_it[i].stat[0] = ctr->items[trad->drag_sell].stat[0];
    trad->inv_it[i].stat[1] = ctr->items[trad->drag_sell].stat[1];
    trad->inv_it[i].type = ctr->items[trad->drag_sell].type;
    trad->inv_it[i].price = ctr->items[trad->drag_sell].price;
    sfSprite_destroy(trad->sell_drag_item.spt);
    trad->sell_drag_item.spt = sfSprite_create();
    sfSprite_setTextureRect(trad->sell_drag_item.spt, \
    (sfIntRect){0, 0, 64, 64});
    ctr->player->gold -= trad->sel_it[trad->drag_sell].price;
}

void trader_mouse_unclick_sell_to_inv(ctr_t *ctr, trader_t *trad)
{
    for (int i = 0; i != NB_INV; ++i) {
        if ((i == 0 && trad->sell_drag_item.type != 2) || \
        (i == 1 && trad->sell_drag_item.type != 3) || (i == 2 && \
        (trad->sell_drag_item.type != 1 && trad->sell_drag_item.type != 0)))
            continue;
        if (trad->m_pos_f.x >= trad->item_pos[i].x && \
        trad->m_pos_f.x <= trad->item_lim_pos[i].x && \
        trad->m_pos_f.y >= trad->item_pos[i].y && \
        trad->m_pos_f.y <= trad->item_lim_pos[i].y && \
        !trad->inv_it[i].spt && \
        ctr->player->gold >= trad->sel_it[trad->drag_sell].price) {
            trader_drop_sell_in_inv(ctr, trad, i);
        }
    }
}

void trader_mouse_unclick_sell(ctr_t *ctr, trader_t *trad)
{
    if (trad->m_pos_f.x >= INV_HITBOX_X_MIN && trad->m_pos_f.x <= \
    INV_HITBOX_X_MAX && trad->m_pos_f.y >= INV_HITBOX_Y_MIN && \
    trad->m_pos_f.y <= INV_HITBOX_Y_MAX) {
        trader_mouse_unclick_sell_to_inv(ctr, trad);
        return;
    }
}
