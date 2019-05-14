/*
** EPITECH PROJECT, 2019
** menu_destroy.c
** File description:
** destroy all created items in menu
*/

#include "menu.h"

void clean_menu(button_t **button, menu_t *menu, button_t *save_button)
{
    for (int i = 0; i != BUT_S; ++i)
        sfText_destroy((*button)[i].txt);
    if (menu->nb_save) {
        for (int i = 0; i != menu->nb_save; ++i)
            free(menu->tmp[i]);
        free(menu->tmp);
    }
    free(save_button);
}
