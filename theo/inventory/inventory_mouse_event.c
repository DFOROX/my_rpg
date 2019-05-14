/*
** EPITECH PROJECT, 2019
** inventory_mouse_event.c
** File description:
** manage mouse event
*/

#include "inventory.h"

void inventory_drop_apply(inventory_t *inv, int i)
{
    item_t tmp = inv->inv_it[i];
    sfVector2f tmp_pos = inv->item->pos;

    if (!inv->inv_it[i].spt) {
        inv->inv_it[i] = inv->inv_it[inv->drag_item];
        inv->inv_it[inv->drag_item] = (item_t){0};
        inv->inv_it[i].pos = inv->item_pos[i];
        inv->item = NULL;
        return;
    }
    inv->inv_it[i] = *inv->item;
    inv->inv_it[inv->drag_item] = tmp;
    inv->inv_it[i].pos = inv->item_pos[i];
    inv->inv_it[inv->drag_item].pos = tmp_pos;
    inv->item = NULL;
}

void inventory_drop(ctr_t *ctr, inventory_t *inventory, int i)
{
    item_t *tmp = ctr->inv_it[i];

    inventory_drop_apply(inventory, i);
    if (!ctr->inv_it[i]) {
        ctr->inv_it[i] = ctr->inv_it[inventory->drag_item];
        ctr->inv_it[inventory->drag_item] = NULL;
        inventory->item = NULL;
        return;
    }
    ctr->inv_it[i] = inventory->item;
    ctr->inv_it[inventory->drag_item] = tmp;
    inventory->item = NULL;
}

int can_drop(inventory_t *inv, int i)
{
    if (!inv->inv_it[i].spt)
        return (1);
    if (inv->drag_item > 1 && inv->inv_it[i].type != inv->item->type)
        return (0);
    if (inv->drag_item < 2 && inv->inv_it[i].type > 1)
        return (0);
    return (1);
}

void inventory_mouse_unclick(ctr_t *ctr, inventory_t *inv)
{
    if (inv->mouse_pos_f.x < INV_HITBOX_X_MIN && inv->mouse_pos_f.x > \
    INV_HITBOX_X_MAX && inv->mouse_pos_f.y < INV_HITBOX_Y_MIN && \
    inv->mouse_pos_f.y > INV_HITBOX_Y_MAX)
        return;
    for (int i = 0; i != NB_INV; ++i) {
        if ((i == 0 && inv->item->type != 2) || \
        (i == 1 && inv->item->type != 3) || (i == 2 && \
        (inv->item->type != 1 && inv->item->type != 0)))
            continue;
        if (inv->mouse_pos_f.x >= inv->item_pos[i].x && \
        inv->mouse_pos_f.x <= inv->item_lim_po[i].x && \
        inv->mouse_pos_f.y >= inv->item_pos[i].y && \
        inv->mouse_pos_f.y <= inv->item_lim_po[i].y && can_drop(inv, i)) {
            inventory_drop(ctr, inv, i);
            return;
        }
    }
}

void inventory_mouse_click(inventory_t *inv)
{
    if (inv->mouse_pos_f.x < INV_HITBOX_X_MIN && inv->mouse_pos_f.x > \
    INV_HITBOX_X_MAX && inv->mouse_pos_f.y < INV_HITBOX_Y_MIN && \
    inv->mouse_pos_f.y > INV_HITBOX_Y_MAX)
        return;
    for (int i = 0; i != NB_INV; ++i) {
        if (!inv->inv_it[i].spt)
            continue;
        if (inv->mouse_pos_f.x >= inv->item_pos[i].x && \
        inv->mouse_pos_f.x <= inv->item_lim_po[i].x && \
        inv->mouse_pos_f.y >= inv->item_pos[i].y && \
        inv->mouse_pos_f.y <= inv->item_lim_po[i].y) {
            inv->drag_item = i;
            inv->item = &inv->inv_it[i];
            my_strcpy(inv->str_item_lore, inv->item->name);
            sfText_setString(inv->item_lore_txt, inv->str_item_lore);
            return;
        }
    }
}
