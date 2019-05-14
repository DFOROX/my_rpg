/*
** EPITECH PROJECT, 2019
** trader_mouse_unclick_inv.c
** File description:
** manage unclick mouse event
*/

#include "trader.h"

void trader_drop_in_inv_apply(trader_t *trad, int i)
{
    item_t tmp = trad->inv_it[i];
    sfVector2f tmp_pos = trad->inv_drag_item->pos;

    if (!trad->inv_it[i].spt) {
        trad->inv_it[i] = trad->inv_it[trad->drag_inv];
        trad->inv_it[trad->drag_inv] = (item_t){0};
        trad->inv_it[i].pos = trad->item_pos[i];
        trad->inv_drag_item = NULL;
        return;
    }
    trad->inv_it[i] = *trad->inv_drag_item;
    trad->inv_it[trad->drag_inv] = tmp;
    trad->inv_it[i].pos = trad->item_pos[i];
    trad->inv_it[trad->drag_inv].pos = tmp_pos;
    trad->inv_drag_item = NULL;

}

void trader_drop_in_inv(ctr_t *ctr, trader_t *trad, int i)
{
    item_t *tmp = ctr->inv_it[i];

    trader_drop_in_inv_apply(trad, i);
    if (!ctr->inv_it[i]) {
        ctr->inv_it[i] = ctr->inv_it[trad->drag_inv];
        ctr->inv_it[trad->drag_inv] = NULL;
        trad->inv_drag_item = NULL;
        return;
    }
    ctr->inv_it[i] = trad->inv_drag_item;
    ctr->inv_it[trad->drag_inv] = tmp;
    trad->inv_drag_item = NULL;
}

int trader_can_drop_inv_to_inv(trader_t *trad, int i)
{
    if (!trad->inv_it[i].spt)
        return (1);
    if (trad->drag_inv < 2 && trad->inv_it[i].type != trad->inv_drag_item->type)
        return (0);
    if (trad->drag_inv == 2 && trad->inv_it[i].type > 1)
        return (0);
    return (1);
}

void trader_mouse_unclick_inv_to_inv(ctr_t *ctr, trader_t *trad)
{
    for (int i = 0; i != NB_INV; ++i) {
        if ((i == 0 && trad->inv_drag_item->type != 2) || \
        (i == 1 && trad->inv_drag_item->type != 3) || (i == 2 && \
        (trad->inv_drag_item->type != 1 && trad->inv_drag_item->type != 0)))
            continue;
        if (trad->m_pos_f.x >= trad->item_pos[i].x && \
        trad->m_pos_f.x <= trad->item_lim_pos[i].x && \
        trad->m_pos_f.y >= trad->item_pos[i].y && \
        trad->m_pos_f.y <= trad->item_lim_pos[i].y && \
        trader_can_drop_inv_to_inv(trad, i)) {
            trader_drop_in_inv(ctr, trad, i);
            return;
        }
    }
}

void trader_mouse_unclick_inv(ctr_t *ctr, trader_t *trad)
{
    if (trad->m_pos_f.x >= INV_HITBOX_X_MIN && trad->m_pos_f.x <= \
    INV_HITBOX_X_MAX && trad->m_pos_f.y >= INV_HITBOX_Y_MIN && \
    trad->m_pos_f.y <= INV_HITBOX_Y_MAX) {
        trader_mouse_unclick_inv_to_inv(ctr, trad);
        return;
    }
    if (trad->m_pos_f.x >= SELL_HITBOX_X_MIN && trad->m_pos_f.x <= \
    SELL_HITBOX_X_MAX && trad->m_pos_f.y >= SELL_HITBOX_Y_MIN && \
    trad->m_pos_f.y <= SELL_HITBOX_Y_MAX) {
        trader_mouse_unclick_inv_to_sell(ctr, trad);
    }
}
