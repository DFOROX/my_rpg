/*
** EPITECH PROJECT, 2019
** trader_init_sell_items.c
** File description:
** init sell items
*/

#include "trader.h"

void trader_sell_init_items(ctr_t *ctr, trader_t *trad)
{
    for (int i = 0; i != NB_ITEM; ++i) {
        if (!ctr->items[i].spt)
            continue;
        trad->sel_it[i].spt = sfSprite_create();
        trad->sel_it[i].name = ctr->items[i].name;
        trad->sel_it[i].id = ctr->items[i].id;
        trad->sel_it[i].stat[0] = ctr->items[i].stat[0];
        trad->sel_it[i].stat[1] = ctr->items[i].stat[1];
        trad->sel_it[i].type = ctr->items[i].type;
        trad->sel_it[i].price = ctr->items[i].price;
        sfSprite_setTexture(trad->sel_it[i].spt, ctr->items[i].text, sfTrue);
        sfSprite_setTextureRect(trad->sel_it[i].spt, \
        (sfIntRect){0, 0, 64, 64});
    }
}

void trader_fill_sell_items_pos(trader_t *trad)
{
    sfVector2f trad_pos[NB_ITEM] = {{WEAPON_1_X, WEAPON_1_Y}, {STAFF_1_X, \
    STAFF_1_Y}, {HELMET_1_X, HELMET_1_Y}, {ARMOR_1_X, ARMOR_1_Y}, {WEAPON_2_X, \
    WEAPON_2_Y}, {STAFF_2_X, STAFF_2_Y}, {HELMET_2_X, HELMET_2_Y}, {ARMOR_2_X, \
    ARMOR_2_Y}, {WEAPON_3_X, WEAPON_3_Y}, {STAFF_3_X, STAFF_3_Y}, {HELMET_3_X, \
    HELMET_3_Y}, {ARMOR_3_X, ARMOR_3_Y}, {WEAPON_4_X, WEAPON_4_Y}, {STAFF_4_X, \
    STAFF_4_Y}, {HELMET_4_X, HELMET_4_Y}, {ARMOR_4_X, ARMOR_4_Y}};
    sfVector2f trad_pos_hit[NB_ITEM] = {{WEAPON_1_LIM_X, WEAPON_1_LIM_Y}, \
    {STAFF_1_LIM_X, STAFF_1_LIM_Y}, {HELMET_1_LIM_X, HELMET_1_LIM_Y}, \
    {ARMOR_1_LIM_X, ARMOR_1_LIM_Y}, {WEAPON_2_LIM_X, WEAPON_2_LIM_Y}, \
    {STAFF_2_LIM_X, STAFF_2_LIM_Y}, {HELMET_2_LIM_X, HELMET_2_LIM_Y}, \
    {ARMOR_2_LIM_X, ARMOR_2_LIM_Y}, {WEAPON_3_LIM_X, WEAPON_3_LIM_Y}, \
    {STAFF_3_LIM_X, STAFF_3_LIM_Y}, {HELMET_3_LIM_X, HELMET_3_LIM_Y}, \
    {ARMOR_3_LIM_X, ARMOR_3_LIM_Y}, {WEAPON_4_LIM_X, WEAPON_4_LIM_Y}, \
    {STAFF_4_LIM_X, STAFF_4_LIM_Y}, {HELMET_4_LIM_X, HELMET_4_LIM_Y}, \
    {ARMOR_4_LIM_X, ARMOR_4_LIM_Y}, };

    for (int i = 0; i != NB_ITEM; ++i) {
        trad->sell_pos[i] = trad_pos[i];
        trad->sell_lim_pos[i] = trad_pos_hit[i];
    }
}

void trader_set_sell_items_pos(trader_t *trad)
{
    for (int i = 0; i != NB_ITEM; ++i) {
        if (!trad->sel_it[i].spt)
            continue;
        sfSprite_setPosition(trad->sel_it[i].spt, trad->sell_pos[i]);
    }
}
