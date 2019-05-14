/*
** EPITECH PROJECT, 2019
** trader_event.c
** File description:
** manage event
*/

#include "trader.h"

void trader_mouse_event(ctr_t *ctr, trader_t *trad)
{
    if ((trad->drag_inv == -1 && trad->drag_sell == -1) && \
    sfMouse_isButtonPressed(sfMouseLeft)) {
        trader_mouse_click(ctr, trad);
        return;
    }
    else if (!sfMouse_isButtonPressed(sfMouseLeft) && \
    (trad->drag_inv != -1 || trad->drag_sell != -1)) {
        if (trad->drag_inv != -1 && trad->drag_sell == -1) {
            trader_mouse_unclick_inv(ctr, trad);
            trad->drag_inv = -1;
        }
        if (trad->drag_sell != -1 || trad->drag_inv != -1) {
            trader_mouse_unclick_sell(ctr, trad);
            trad->drag_sell = -1;
        }
        trader_set_inventory_items_pos(trad);
    }
}

void trader_event(ctr_t *ctr, int *state, trader_t *trad)
{
    if (ctr->event.type == sfEvtClosed) {
        sfRenderWindow_close(ctr->window);
        return;
    }
    if ((sfKeyboard_isKeyPressed(sfKeyI) || \
    sfKeyboard_isKeyPressed(sfKeyEscape)) && trad->is_empty == 0) {
        while (sfKeyboard_isKeyPressed(sfKeyI) || \
        sfKeyboard_isKeyPressed(sfKeyEscape))
            *state = 0;
        return;
    }
    trader_mouse_event(ctr, trad);
}
