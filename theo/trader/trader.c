/*
** EPITECH PROJECT, 2019
** trader.c
** File description:
** main function of trader
*/

#include "trader.h"

void trader_check_equipment_is_empty(trader_t *trad)
{
    for (int i = 0; i != 3; ++i)
        if (!trad->inv_it[i].spt) {
            trad->is_empty = 1;
            return;
        }
    trad->is_empty = 0;
}

void main_trader(ctr_t *ctr)
{
    trader_t trad = {0};
    int state = 1;

    trader_init(ctr, &trad);
    while (state == 1 && sfRenderWindow_isOpen(ctr->window)) {
        trader_check_equipment_is_empty(&trad);
        trad.m_pos = sfMouse_getPositionRenderWindow(ctr->window);
        trad.m_pos_f = (sfVector2f){trad.m_pos.x, trad.m_pos.y};
        while (sfRenderWindow_pollEvent(ctr->window, &ctr->event))
            trader_event(ctr, &state, &trad);
        if (trad.drag_inv != -1 || trad.drag_sell != -1)
            trader_mouse_drag(&trad);
        draw_trader(ctr, &trad);
    }
    trader_destroy(&trad);
}
