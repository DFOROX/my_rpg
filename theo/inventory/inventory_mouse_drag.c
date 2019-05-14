/*
** EPITECH PROJECT, 2019
** inventory_mouse_drag.c
** File description:
** manage the follow of item
*/

#include "inventory.h"

void inventory_mouse_drag(ctr_t *ctr, inventory_t *inventory)
{
    if (inventory->drag_item == -1)
        return;
    inventory->mouse_pos = sfMouse_getPositionRenderWindow(ctr->window);
    sfSprite_setPosition(inventory->item->spt, \
    (sfVector2f){inventory->mouse_pos.x - 32, inventory->mouse_pos.y - 32});
    sfText_setPosition(inventory->item_lore_txt, \
    (sfVector2f){inventory->mouse_pos.x  + 35, inventory->mouse_pos.y - 32});
}
