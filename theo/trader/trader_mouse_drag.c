/*
** EPITECH PROJECT, 2019
** trader_mouse_drag.c
** File description:
** manage the follow of item
*/

#include "trader.h"

void trader_mouse_drag(trader_t *trad)
{
    if (trad->drag_inv != -1) {
        sfSprite_setPosition(trad->inv_drag_item->spt, \
        (sfVector2f){trad->m_pos_f.x - 32, trad->m_pos_f.y - 32});
        sfText_setPosition(trad->item_lore_txt, \
        (sfVector2f){trad->m_pos_f.x + 35, trad->m_pos_f.y - 32});
        return;
    }
    if (trad->drag_sell != -1) {
        sfSprite_setPosition(trad->sell_drag_item.spt, \
        (sfVector2f){trad->m_pos_f.x - 32, trad->m_pos_f.y - 32});
        sfText_setPosition(trad->item_lore_txt, \
        (sfVector2f){trad->m_pos_f.x + 35, trad->m_pos_f.y - 32});
        return;
    }
}
