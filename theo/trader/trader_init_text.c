/*
** EPITECH PROJECT, 2019
** trader_init_text.c
** File description:
** init texts of the trader
*/

#include "trader.h"

void trader_init_trader_message(ctr_t *ctr, trader_t *trad)
{
    char *str[] = {"Cost:", "Gold:", "0", "0"};

    for (int i= 0; i != NB_TRADER_MESSAGE; ++i) {
        my_strcpy(trad->trader_msg[i].str, str[i]);
        trad->trader_msg[i].txt = sfText_create();
        trad->trader_msg[i].pos = \
        (sfVector2f){TRADER_MESSAGE_X_MIN + (i < TRADER_MESSAGE_FIX ? 0 : 80), \
        TRADER_MESSAGE_Y_MIN + (i < TRADER_MESSAGE_FIX ? i * 32 : \
        (i - TRADER_MESSAGE_FIX) * 32)};
        sfText_setString(trad->trader_msg[i].txt, \
        trad->trader_msg[i].str);
        sfText_setFont(trad->trader_msg[i].txt, ctr->obj[2].font);
        sfText_setCharacterSize(trad->trader_msg[i].txt, TRADER_MESSAGE_SIZE);
        sfText_setColor(trad->trader_msg[i].txt, (sfColor){255, 255, 255, 255});
        sfText_setPosition(trad->trader_msg[i].txt, trad->trader_msg[i].pos);
    }
}

void trader_init_lore_message(ctr_t *ctr, trader_t *trad)
{
    trad->item_lore_txt = sfText_create();
    sfText_setFont(trad->item_lore_txt, ctr->obj[2].font);
    sfText_setCharacterSize(trad->item_lore_txt, 18);
    sfText_setColor(trad->item_lore_txt, (sfColor){255, 255, 0, 255});
    sfText_setPosition(trad->item_lore_txt, (sfVector2f){0, 0});
}

void trader_init_warning_message(ctr_t *ctr, trader_t *trad)
{
    trad->warning_txt = sfText_create();
    sfText_setString(trad->warning_txt, "You can't be unequiped.");
    sfText_setFont(trad->warning_txt, ctr->obj[2].font);
    sfText_setCharacterSize(trad->warning_txt, 52);
    sfText_setColor(trad->warning_txt, (sfColor){255, 0, 0, 255});
    sfText_setPosition(trad->warning_txt, \
    (sfVector2f){POS_INVENTORY_X, POS_INVENTORY_Y + INVENTORY_HEIGHT});
}
