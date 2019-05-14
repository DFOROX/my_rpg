/*
** EPITECH PROJECT, 2019
** inventory_init.c
** File description:
** init inventory
*/

#include "inventory.h"

void set_text_default_val(stat_inventory_t *stat, int i, int x_pos)
{
    stat->s_txt = 18;
    stat->color[0] = (sfColor){0, 0, 0, 255};
    stat->color[1] = (sfColor){200, 200, 200, 255};
    stat->color[2] = (sfColor){255, 255, 0, 192};
    stat->pos3 = (sfVector2f){x_pos, 32 * (i + 1) + STAT_Y_MIN};
}

void inventory_text(ctr_t *ctr, stat_inventory_t **stats, \
char *str[], int arr[])
{
    for (int i = 0; i != TEXT_NB - 1; ++i) {
        (*stats)[i].txt = sfText_create();
        if (i < STAT_FIX) {
            my_strcpy((*stats)[i].str, str[i]);
            set_text_default_val((*stats) + i, i, STAT_X_MIN);
        } else {
            my_ito_str(arr[i - STAT_FIX], (*stats)[i].str);
            set_text_default_val((*stats) + i, i - STAT_FIX, STAT_X_MIN + 120);
        }
        sfText_setString((*stats)[i].txt, (*stats)[i].str);
        sfText_setFont((*stats)[i].txt, ctr->obj[7].font);
        sfText_setCharacterSize((*stats)[i].txt, 18);
        sfText_setColor((*stats)[i].txt, (*stats)[i].color[0]);
        sfText_setPosition((*stats)[i].txt, (*stats)[i].pos3);
    }
    (*stats)[TEXT_NB - 1].txt = sfText_create();
    my_ito_str(ctr->player->hp_max, (*stats)[TEXT_NB - 1].str);
    set_text_default_val((*stats) + TEXT_NB - 1, 0, STAT_X_MIN + 190);
    sfText_setString((*stats)[TEXT_NB - 1].txt, (*stats)[TEXT_NB - 1].str);
}

void inventory_init_warning_message(ctr_t *ctr, inventory_t *inventory)
{
    inventory->warning_txt = sfText_create();
    sfText_setString(inventory->warning_txt, "You can't be unequiped.");
    sfText_setFont(inventory->warning_txt, ctr->obj[2].font);
    sfText_setCharacterSize(inventory->warning_txt, 52);
    sfText_setColor(inventory->warning_txt, (sfColor){255, 0, 0, 255});
    sfText_setPosition(inventory->warning_txt, \
    (sfVector2f){POS_INVENTORY_X, POS_INVENTORY_Y + INVENTORY_HEIGHT});
}

void inventory_init_item_lore_message(ctr_t *ctr, inventory_t *inventory)
{
    inventory->item_lore_txt = sfText_create();
    sfText_setFont(inventory->item_lore_txt, ctr->obj[2].font);
    sfText_setCharacterSize(inventory->item_lore_txt, 18);
    sfText_setColor(inventory->item_lore_txt, (sfColor){255, 255, 0, 255});
    sfText_setPosition(inventory->item_lore_txt, (sfVector2f){0, 0});
}

void init_inventory(ctr_t *ctr, stat_inventory_t **stats, \
inventory_t *inventory)
{
    char *str[] = {"Life:", "Strength:", "Intelligence:", "Speed:", "Level:", \
    "Experience:", "Gold:", "Stats Capital:", "Skill points:"};
    int arr[] = {ctr->player->life, ctr->player->stat[1], \
    ctr->player->stat[0], ctr->player->speed, ctr->player->lvl, \
    ctr->player->xp, ctr->player->gold, 0, 0};

    inventory->drag_item = -1;
    inventory_sprite(ctr);
    if (!inventory->item_pos[0].x)
        static_item_pos(inventory);
    inventory_init_items(ctr, inventory);
    inventory_init_items_pos(inventory);
    inventory_init_warning_message(ctr, inventory);
    inventory_init_item_lore_message(ctr, inventory);
    inventory_text(ctr, stats, str, arr);
    sfText_setCharacterSize((*stats)[TEXT_NB - 1].txt, 18);
    sfText_setFont((*stats)[TEXT_NB - 1].txt, ctr->obj[7].font);
    sfText_setColor((*stats)[TEXT_NB - 1].txt, (*stats)[TEXT_NB - 1].color[0]);
    sfText_setPosition((*stats)[TEXT_NB - 1].txt, (*stats)[TEXT_NB - 1].pos3);
}
