/*
** EPITECH PROJECT, 2019
** trader_mouse_click.c
** File description:
** manage mouse click event
*/

#include "trader.h"

int trader_mouse_collide(trader_t *trad)
{
    if (trad->m_pos_f.x >= INV_HITBOX_X_MIN && \
    trad->m_pos_f.x <= INV_HITBOX_X_MAX && \
    trad->m_pos_f.y >= INV_HITBOX_Y_MIN && \
    trad->m_pos_f.y <= INV_HITBOX_Y_MAX) {
        return (1);
}
    if (trad->m_pos_f.x >= SELL_HITBOX_X_MIN && \
    trad->m_pos_f.x <= SELL_HITBOX_X_MAX && \
    trad->m_pos_f.y >= \
    SELL_HITBOX_Y_MIN && \
    trad->m_pos_f.y <= SELL_HITBOX_Y_MAX)
        return (2);
    return (0);
}

void trader_mouse_click_inv(trader_t *trad)
{
    for (int i = 0; i != NB_INV; ++i) {
        if (!trad->inv_it[i].spt)
            continue;
        if (trad->m_pos_f.x >= trad->item_pos[i].x && \
        trad->m_pos_f.x <= trad->item_lim_pos[i].x && \
        trad->m_pos_f.y >= trad->item_pos[i].y && \
        trad->m_pos_f.y <= trad->item_lim_pos[i].y) {
            trad->drag_inv = i;
            trad->inv_drag_item = &trad->inv_it[i];
            my_strcpy(trad->item_lore_str, trad->inv_drag_item->name);
            sfText_setString(trad->item_lore_txt, trad->item_lore_str);
            return;
        }
    }
}

void trader_mouse_click_sell(ctr_t *ctr, trader_t *trad)
{
    for (int i = 0; i != NB_ITEM; ++i) {
        if (trad->m_pos_f.x >= trad->sell_pos[i].x && \
        trad->m_pos_f.x <= trad->sell_lim_pos[i].x && \
        trad->m_pos_f.y >= trad->sell_pos[i].y && \
        trad->m_pos_f.y <= trad->sell_lim_pos[i].y) {
            trad->drag_sell = i;
            trad->sell_drag_item.pos = trad->sel_it[i].pos;
            trad->sell_drag_item.name = trad->sel_it[i].name;
            trad->sell_drag_item.type = trad->sel_it[i].type;
            trad->sell_drag_item.price = trad->sel_it[i].price;
            sfSprite_setTexture(trad->sell_drag_item.spt, \
            ctr->items[i].text, sfTrue);
            my_strcpy(trad->item_lore_str, trad->sell_drag_item.name);
            sfText_setString(trad->item_lore_txt, trad->item_lore_str);
            return;
        }
    }
}

void trader_mouse_click(ctr_t *ctr, trader_t *trad)
{
    int collide_info = trader_mouse_collide(trad);

    if (!collide_info)
        return;
    if (collide_info == 1) {
        trader_mouse_click_inv(trad);
        return;
    } else if (collide_info == 2) {
        trader_mouse_click_sell(ctr, trad);
    }
}
