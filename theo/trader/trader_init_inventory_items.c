/*
** EPITECH PROJECT, 2019
** trader_init.c
** File description:
** init all trader info
*/

#include "trader.h"

void trader_sprite(ctr_t *ctr)
{
    ctr->obj[22].rect.top = 0;
    ctr->obj[22].rect.left = 0;
    ctr->obj[22].rect.width = INVENTORY_WIDTH;
    ctr->obj[22].rect.height = INVENTORY_HEIGHT;
    ctr->obj[22].v2f.x = POS_INVENTORY_X;
    ctr->obj[22].v2f.y = POS_INVENTORY_Y;
    sfSprite_setPosition(ctr->obj[22].spt, ctr->obj[22].v2f);
}

void trader_inventory_init_items(ctr_t *ctr, trader_t *trad)
{
    for (int i = 0; i != NB_INV; ++i) {
        if (!ctr->inv_it[i])
            continue;
        trad->inv_it[i].spt = sfSprite_create();
        trad->inv_it[i].name = ctr->inv_it[i]->name;
        trad->inv_it[i].id = ctr->inv_it[i]->id;
        trad->inv_it[i].stat[0] = ctr->inv_it[i]->stat[0];
        trad->inv_it[i].stat[1] = ctr->inv_it[i]->stat[1];
        trad->inv_it[i].type = ctr->inv_it[i]->type;
        trad->inv_it[i].price = ctr->inv_it[i]->price;
        sfSprite_setTexture(trad->inv_it[i].spt, ctr->inv_it[i]->text, sfTrue);
        sfSprite_setTextureRect(trad->inv_it[i].spt, (sfIntRect){0, 0, 64, 64});
    }
    trad->sell_drag_item.spt = sfSprite_create();
    sfSprite_setTextureRect(trad->sell_drag_item.spt, \
    (sfIntRect){0, 0, 64, 64});
}

void trader_fill_inventory_items_pos(trader_t *trad)
{
    sfVector2f inv_pos[NB_INV] = {{HELMET_POS_X, HELMET_POS_Y}, {ARMOR_POS_X, \
    ARMOR_POS_Y}, {WEAPON_POS_X, WEAPON_POS_Y}, {CASE_1_X, CASE_1_Y}, \
    {CASE_2_X, CASE_2_Y}, {CASE_3_X, CASE_3_Y}, {CASE_4_X, CASE_4_Y}};
    sfVector2f inv_hit[NB_INV] = {{HELMET_LIM_X, HELMET_LIM_Y}, { ARMOR_LIM_X, \
    ARMOR_LIM_Y}, {WEAPON_LIM_X, WEAPON_LIM_Y}, {CASE_1_LIM_X, CASE_1_LIM_Y}, \
    {CASE_2_LIM_X, CASE_2_LIM_Y}, {CASE_3_LIM_X, CASE_3_LIM_Y}, {CASE_4_LIM_X, \
    CASE_4_LIM_Y}};

    for (int i = 0; i != NB_INV; ++i) {
        trad->item_pos[i] = inv_pos[i];
        trad->item_lim_pos[i] = inv_hit[i];
    }
}

void trader_set_inventory_items_pos(trader_t *trad)
{
    for (int i = 0; i != NB_INV; ++i) {
        if (!trad->inv_it[i].spt)
            continue;
        sfSprite_setPosition(trad->inv_it[i].spt, trad->item_pos[i]);
    }
}

void trader_init(ctr_t *ctr, trader_t *trad)
{
    trad->drag_inv = -1;
    trad->drag_sell = -1;
    trader_sprite(ctr);
    trader_inventory_init_items(ctr, trad);
    trader_fill_inventory_items_pos(trad);
    trader_set_inventory_items_pos(trad);
    trader_sell_init_items(ctr, trad);
    trader_fill_sell_items_pos(trad);
    trader_set_sell_items_pos(trad);
    trader_init_warning_message(ctr, trad);
    trader_init_lore_message(ctr, trad);
    trader_init_trader_message(ctr, trad);
}
