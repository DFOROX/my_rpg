/*
** EPITECH PROJECT, 2019
** inventory_init_items.c
** File description:
** init items
*/

#include "inventory.h"

void inventory_sprite(ctr_t *ctr)
{
    ctr->obj[21].rect.top = 0;
    ctr->obj[21].rect.left = 0;
    ctr->obj[21].rect.width = INVENTORY_WIDTH;
    ctr->obj[21].rect.height = INVENTORY_HEIGHT;
    ctr->obj[21].v2f.x = POS_INVENTORY_X;
    ctr->obj[21].v2f.y = POS_INVENTORY_Y;
    sfSprite_setPosition(ctr->obj[21].spt, ctr->obj[21].v2f);
}

void static_item_pos(inventory_t *inventory)
{
    sfVector2f inv_pos[NB_INV] = {{HELMET_POS_X, HELMET_POS_Y}, {ARMOR_POS_X, \
    ARMOR_POS_Y}, {WEAPON_POS_X, WEAPON_POS_Y}, {CASE_1_X, CASE_1_Y}, \
    {CASE_2_X, CASE_2_Y}, {CASE_3_X, CASE_3_Y}, {CASE_4_X, CASE_4_Y}};
    sfVector2f inv_hit[NB_INV] = {{HELMET_LIM_X, HELMET_LIM_Y}, { ARMOR_LIM_X, \
    ARMOR_LIM_Y}, {WEAPON_LIM_X, WEAPON_LIM_Y}, {CASE_1_LIM_X, CASE_1_LIM_Y}, \
    {CASE_2_LIM_X, CASE_2_LIM_Y}, {CASE_3_LIM_X, CASE_3_LIM_Y}, {CASE_4_LIM_X, \
    CASE_4_LIM_Y}};

    for (int i = 0; i != NB_INV; ++i) {
        inventory->item_pos[i] = inv_pos[i];
        inventory->item_lim_po[i] = inv_hit[i];
    }
}

void inventory_init_items_pos(inventory_t *inventory)
{
    for (int i = 0; i != NB_INV; ++i) {
        if (!inventory->inv_it[i].spt)
            continue;
        sfSprite_setPosition(inventory->inv_it[i].spt, inventory->item_pos[i]);
    }
}

void inventory_init_items(ctr_t *ctr, inventory_t *inv)
{
    for (int i = 0; i != NB_INV; ++i) {
        if (!ctr->inv_it[i])
            continue;
        inv->inv_it[i].spt = sfSprite_create();
        inv->inv_it[i].name = ctr->inv_it[i]->name;
        inv->inv_it[i].id = ctr->inv_it[i]->id;
        inv->inv_it[i].stat[0] = ctr->inv_it[i]->stat[0];
        inv->inv_it[i].stat[1] = ctr->inv_it[i]->stat[1];
        inv->inv_it[i].type = ctr->inv_it[i]->type;
        inv->inv_it[i].price = ctr->inv_it[i]->price;
        sfSprite_setTexture(inv->inv_it[i].spt, ctr->inv_it[i]->text, sfTrue);
        sfSprite_setTextureRect(inv->inv_it[i].spt, (sfIntRect){0, 0, 64, 64});
    }
    inventory_init_items_pos(inv);
}
