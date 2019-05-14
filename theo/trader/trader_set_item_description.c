/*
** EPITECH PROJECT, 2019
** trader_set_item_description.c
** File description:
** set description's item string
*/

#include "trader.h"

void trader_inventory_item_description_set_string(trader_t *trad, int i)
{
    my_strcpy(trad->item_lore_str, trad->inv_it[i].name);
    my_strcat(trad->item_lore_str, "\n");
    if (trad->inv_it[i].type < 2) {
        my_strcat(trad->item_lore_str, "attak: ");
        my_strcat(trad->item_lore_str, my_itoa_static(trad->inv_it[i].stat[0]));
        my_strcat(trad->item_lore_str, " - ");
        my_strcat(trad->item_lore_str, my_itoa_static(trad->inv_it[i].stat[1]));
    } else {
        my_strcat(trad->item_lore_str, "defence Phy: ");
        my_strcat(trad->item_lore_str, my_itoa_static(trad->inv_it[i].stat[0]));
        my_strcat(trad->item_lore_str, "\ndefence Mag: ");
        my_strcat(trad->item_lore_str, my_itoa_static(trad->inv_it[i].stat[1]));
    }
    my_strcat(trad->item_lore_str, "\n");
    my_strcat(trad->item_lore_str, "Price: ");
    my_strcat(trad->item_lore_str, my_itoa_static(trad->inv_it[i].price));
    sfText_setString(trad->item_lore_txt, trad->item_lore_str);
    sfText_setPosition(trad->item_lore_txt, \
    (sfVector2f){trad->item_pos[i].x, trad->item_pos[i].y + 65});
}

void trader_sell_item_description_set_string(trader_t *trad, int i)
{
    my_strcpy(trad->item_lore_str, trad->sel_it[i].name);
    my_strcat(trad->item_lore_str, "\n");
    if (trad->sel_it[i].type < 2) {
        my_strcat(trad->item_lore_str, "attak: ");
        my_strcat(trad->item_lore_str, my_itoa_static(trad->sel_it[i].stat[0]));
        my_strcat(trad->item_lore_str, " - ");
        my_strcat(trad->item_lore_str, my_itoa_static(trad->sel_it[i].stat[1]));
    } else {
        my_strcat(trad->item_lore_str, "defence Phy: ");
        my_strcat(trad->item_lore_str, my_itoa_static(trad->sel_it[i].stat[0]));
        my_strcat(trad->item_lore_str, "\ndefence Mag: ");
        my_strcat(trad->item_lore_str, my_itoa_static(trad->sel_it[i].stat[1]));
    }
    my_strcat(trad->item_lore_str, "\n");
    my_strcat(trad->item_lore_str, "Price: ");
    my_strcat(trad->item_lore_str, my_itoa_static(trad->sel_it[i].price));
    sfText_setString(trad->item_lore_txt, trad->item_lore_str);
    sfText_setPosition(trad->item_lore_txt, \
    (sfVector2f){trad->sell_pos[i].x, trad->sell_pos[i].y + 65});
}

int trader_item_des_inv(ctr_t *ctr, trader_t *trad, int i)
{
    if (trad->m_pos_f.x >= trad->item_pos[i].x && trad->m_pos_f.x <= \
    trad->item_lim_pos[i].x && trad->m_pos_f.y >= trad->item_pos[i].y && \
    trad->m_pos_f.y <= trad->item_lim_pos[i].y) {
        trader_inventory_item_description_set_string(trad, i);
        sfRenderWindow_drawText(ctr->window, trad->item_lore_txt, NULL);
        sfText_setString(trad->trader_msg[COST_MSG_POS].txt, \
        my_itoa_static(trad->inv_it[i].price));
        return (1);
    }
    return (0);
}

int trader_item_des_sell(ctr_t *ctr, trader_t *trad, int i)
{
    if (trad->m_pos_f.x >= trad->sell_pos[i].x && trad->m_pos_f.x <= \
    trad->sell_lim_pos[i].x && trad->m_pos_f.y >= trad->sell_pos[i].y && \
    trad->m_pos_f.y <= trad->sell_lim_pos[i].y) {
        trader_sell_item_description_set_string(trad, i);
        sfRenderWindow_drawText(ctr->window, trad->item_lore_txt, NULL);
        sfText_setString(trad->trader_msg[COST_MSG_POS].txt, \
        my_itoa_static(trad->sel_it[i].price));
        return (1);
    }
    return (0);
}

void trader_set_item_description(ctr_t *ctr, trader_t *trad)
{
    memset(trad->item_lore_str, 0, 10);
    for (int i = 0; i != NB_ITEM; ++i) {
        if (!trad->sel_it[i].spt)
            continue;
        if (trader_item_des_sell(ctr, trad, i))
            return;
    }
    for (int i = 0; i != NB_INV; ++i) {
        if (!trad->inv_it[i].spt)
            continue;
        if (trader_item_des_inv(ctr, trad, i))
            return;
    }
}
