/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

int main(void)
{
    ctr_t ctr = {0};

    create_ctr(&ctr);
    ctr.game_state = 1;
    while (ctr.game_state != -1 && sfRenderWindow_isOpen(ctr.window)) {
        if (ctr.game_state == 2)
            movement_fight(&ctr);
        if (ctr.game_state == 1)
            main_menu(&ctr);
    }
    destroy_game(&ctr);
    return (0);
}
