/*
** EPITECH PROJECT, 2019
** boss
** File description:
** boss
*/

#include "tarek.h"

monster_t *create_boss(void)
{
    monster_t *monsters = malloc(sizeof(monster_t) * 3);

    monsters[0] = init_monster4(1);
    monsters[1] = init_monster4(1);
    monsters[2].type = 2;
    monsters[2].xp = 10000;
    monsters[2].loot = 100;
    monsters[2].pv = 1000;
    monsters[2].res[0] = 50;
    monsters[2].res[1] = 40;
    monsters[2].dgt_max = 1;
    monsters[2].dgt_min = 0;
    monsters[2].speed = 500;
    monsters[2].name = stupid("boss");
    init_vect_mstr(monsters);
    return (monsters);
}

void boss(ctr_t *data)
{
    monster_t *monsters = create_boss();

    fight_loop(monsters, data);
    if (data->player->life > 0) {
        sfRenderWindow_clear(data->window, sfBlack);
        sfRenderWindow_drawSprite(data->window, data->obj[26].spt, NULL);
        sfRenderWindow_display(data->window);
        while (!sfKeyboard_isKeyPressed(sfKeySpace));
    }
    data->game_state = 1;
}
