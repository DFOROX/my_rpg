/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_player.c
*/

#include "../my.h"

void draw_player(player_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, player->spt, NULL);
    sfSprite_setPosition(player->spt, player->pos);
}

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->spt);
    sfTexture_destroy(player->text);
    free(player);
}
