/*
** EPITECH PROJECT, 2019
** menu_init_how_play.c
** File description:
** init text 3 button
*/

#include "menu.h"

void menu_init_how_play(ctr_t *ctr, menu_t *menu)
{
    memset(menu->htp_str, 0, 256);
    my_strcpy(menu->htp_str, "movement up: key up\nmovement down: key down\n" \
    "movement left: key left\nmovement right: key right\ninventory: key I\n" \
    "action: key space\nGo to tavern in city to heal\nMove to npc to interact");
    menu->htp_txt = sfText_create();
    sfText_setFont(menu->htp_txt, ctr->obj[2].font);
    sfText_setCharacterSize(menu->htp_txt, 22);
    sfText_setColor(menu->htp_txt, (sfColor){255, 255, 255, 255});
    sfText_setString(menu->htp_txt, menu->htp_str);
    sfText_setPosition(menu->htp_txt, (sfVector2f){900, 172});
}
