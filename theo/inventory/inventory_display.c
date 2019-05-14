/*
** EPITECH PROJECT, 2019
** inventory_display.c
** File description:
** display inventory function
*/

#include "inventory.h"

void inventory_item_description_set_string(inventory_t *inv, int i)
{
    my_strcpy(inv->str_item_lore, inv->inv_it[i].name);
    my_strcat(inv->str_item_lore, "\n");
    if (inv->inv_it[i].type < 2) {
        my_strcat(inv->str_item_lore, "attak: ");
        my_strcat(inv->str_item_lore, my_itoa_static(inv->inv_it[i].stat[0]));
        my_strcat(inv->str_item_lore, " - ");
        my_strcat(inv->str_item_lore, my_itoa_static(inv->inv_it[i].stat[1]));
    } else {
        my_strcat(inv->str_item_lore, "defence Phy: ");
        my_strcat(inv->str_item_lore, my_itoa_static(inv->inv_it[i].stat[0]));
        my_strcat(inv->str_item_lore, "\ndefence Mag: ");
        my_strcat(inv->str_item_lore, my_itoa_static(inv->inv_it[i].stat[1]));
    }
    my_strcat(inv->str_item_lore, "\n");
    my_strcat(inv->str_item_lore, "Price: ");
    my_strcat(inv->str_item_lore, my_itoa_static(inv->inv_it[i].price));
}

void inventory_item_description(ctr_t *ctr, inventory_t *inv)
{
    for (int i = 0; i != NB_INV; ++i) {
        if (!inv->inv_it[i].spt)
            continue;
        if (inv->mouse_pos_f.x >= inv->item_pos[i].x && \
        inv->mouse_pos_f.x <= inv->item_lim_po[i].x && \
        inv->mouse_pos_f.y >= inv->item_pos[i].y && \
        inv->mouse_pos_f.y <= inv->item_lim_po[i].y) {
            inventory_item_description_set_string(inv, i);
            sfText_setString(inv->item_lore_txt, inv->str_item_lore);
            sfText_setPosition(inv->item_lore_txt, \
            (sfVector2f){inv->item_pos[i].x, inv->item_pos[i].y + 65});
            sfRenderWindow_drawText(ctr->window, inv->item_lore_txt, NULL);
        }
    }
}

void draw_inventory(ctr_t *ctr, stat_inventory_t **state, \
inventory_t *inventory)
{
    sfRenderWindow_clear(ctr->window, sfBlack);
    sfRenderWindow_drawSprite(ctr->window, ctr->maps[ctr->state].spt, NULL);
    sfRenderWindow_drawSprite(ctr->window, ctr->player->spt, NULL);
    if (ctr->maps[ctr->m].spt2)
        sfRenderWindow_drawSprite(ctr->window, ctr->maps[ctr->m].spt2, NULL);
    sfRenderWindow_drawSprite(ctr->window, ctr->obj[21].spt, NULL);
    for (int i = 0; i != TEXT_NB; ++i)
        sfRenderWindow_drawText(ctr->window, (*state)[i].txt, NULL);
    for (int i = 0; i != NB_INV; ++i) {
        if (!inventory->inv_it[i].spt)
            continue;
        sfRenderWindow_drawSprite(ctr->window, inventory->inv_it[i].spt, NULL);
    }
    inventory_item_description(ctr, inventory);
    set_pos_button(ctr, state);
    if (inventory->is_empty)
        sfRenderWindow_drawText(ctr->window, inventory->warning_txt, NULL);
    if (inventory->drag_item != -1)
        sfRenderWindow_drawText(ctr->window, inventory->item_lore_txt, NULL);
    sfRenderWindow_display(ctr->window);
}