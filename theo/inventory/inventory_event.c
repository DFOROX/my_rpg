/*
** EPITECH PROJECT, 2019
** inventory_event.c
** File description:
** manage event in inventory loop
*/

#include "inventory.h"

void inventory_event(ctr_t *ctr, int *state, inventory_t *inv)
{
    if (ctr->event.type == sfEvtClosed) {
        sfRenderWindow_close(ctr->window);
        return;
    }
    if ((sfKeyboard_isKeyPressed(sfKeyI) || \
    sfKeyboard_isKeyPressed(sfKeyEscape)) && inv->is_empty == 0) {
        while (sfKeyboard_isKeyPressed(sfKeyI) || \
        sfKeyboard_isKeyPressed(sfKeyEscape))
            *state = 0;
        return;
    }
    if (inv->drag_item == -1 && sfMouse_isButtonPressed(sfMouseLeft))
        inventory_mouse_click(inv);
    else if (!sfMouse_isButtonPressed(sfMouseLeft) && \
    inv->drag_item != -1) {
        inventory_mouse_unclick(ctr, inv);
        inventory_init_items(ctr, inv);
        inv->drag_item = -1;
    }
}
