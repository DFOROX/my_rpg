/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** inventory manager
*/

#include "inventory.h"

void inventory_check_equipment_is_empty(inventory_t *inventory)
{
    for (int i = 0; i != 3; ++i)
        if (!inventory->inv_it[i].spt) {
            inventory->is_empty = 1;
            return;
        }
    inventory->is_empty = 0;
}

void main_inventory(ctr_t *ctr, int *state)
{
    stat_inventory_t stats[TEXT_NB] = {0};
    stat_inventory_t *sta = (stat_inventory_t *)stats;
    inventory_t inventory = {0};

    inventory.sta = sta;
    init_inventory(ctr, &sta, &inventory);
    while ((*state == 1) && sfRenderWindow_isOpen(ctr->window)) {
        inventory_check_equipment_is_empty(&inventory);
        inventory.mouse_pos = sfMouse_getPositionRenderWindow(ctr->window);
        inventory.mouse_pos_f = (sfVector2f){inventory.mouse_pos.x, \
        inventory.mouse_pos.y};
        while (sfRenderWindow_pollEvent(ctr->window, &ctr->event))
            inventory_event(ctr, state, &inventory);
        if (inventory.drag_item != -1)
            inventory_mouse_drag(ctr, &inventory);
        draw_inventory(ctr, &sta, &inventory);
        set_pos_click(ctr, &sta);
    }
    inventory_destroy(&sta, &inventory);
}
