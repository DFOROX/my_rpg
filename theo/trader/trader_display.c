/*
** EPITECH PROJECT, 2019
** trader_displey.c
** File description:
** manage display
*/

#include "trader.h"

void draw_trader_bis(ctr_t *ctr, trader_t *trad)
{
    if (trad->drag_inv != -1 || trad->drag_sell != -1) {
        sfRenderWindow_drawText(ctr->window, trad->item_lore_txt, NULL);
        if (trad->drag_sell != -1)
            sfRenderWindow_drawSprite(ctr->window, \
            trad->sell_drag_item.spt, NULL);
    }
    sfText_setString(trad->trader_msg[GOLD_MSG_POS].txt, \
    my_itoa_static(ctr->player->gold));
    for (int i = 0; i != NB_TRADER_MESSAGE; ++i) {
        sfRenderWindow_drawText(ctr->window, trad->trader_msg[i].txt, NULL);
    }
}

void draw_trader(ctr_t *ctr, trader_t *trad)
{
    sfRenderWindow_clear(ctr->window, sfBlack);
    sfRenderWindow_drawSprite(ctr->window, ctr->maps[ctr->state].spt, NULL);
    sfRenderWindow_drawSprite(ctr->window, ctr->player->spt, NULL);
    if (ctr->maps[ctr->m].spt2)
        sfRenderWindow_drawSprite(ctr->window, ctr->maps[ctr->m].spt2, NULL);
    sfRenderWindow_drawSprite(ctr->window, ctr->obj[22].spt, NULL);
    for (int i = 0; i != NB_ITEM; ++i) {
        if (i < NB_INV && trad->inv_it[i].spt) {
            sfRenderWindow_drawSprite(ctr->window, trad->inv_it[i].spt, NULL);
        }
        if (trad->sel_it[i].spt)
            sfRenderWindow_drawSprite(ctr->window, trad->sel_it[i].spt, NULL);
    }
    trader_set_item_description(ctr, trad);
    if (trad->is_empty)
        sfRenderWindow_drawText(ctr->window, trad->warning_txt, NULL);
    draw_trader_bis(ctr, trad);
    sfRenderWindow_display(ctr->window);
}
