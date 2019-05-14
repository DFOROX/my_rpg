/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** tarek
*/

#include "tarek.h"

void init_asset(ctr_t *ctr)
{
    ctr->init_monster[0] = init_monster1;
    ctr->init_monster[1] = NULL;
    ctr->init_monster[2] = init_monster3;
    ctr->init_monster[3] = init_monster4;
    ctr->obj[11].font = sfFont_createFromFile("assets/font/7text.ttf");
    ctr->obj[11].txt = sfText_create();
    ctr->obj[15].font = sfFont_createFromFile("assets/font/7text.ttf");
    ctr->obj[15].txt = sfText_create();
    ctr->player->cpt = 15;
    sfText_setFont(ctr->obj[11].txt, ctr->obj[11].font);
    sfText_setFont(ctr->obj[15].txt, ctr->obj[15].font);
    ctr->pnj[0] = farmer;
    ctr->pnj[1] = guard;
    ctr->pnj[2] = gate;
    ctr->pnj[3] = grote;
    ctr->pnj[4] = boss;
    ctr->pnj[5] = inn;
    ctr->pnj[6] = main_trader;
}

void draw_all(ctr_t *ctr)
{
    sfRenderWindow_clear(ctr->window, sfBlack);
    sfSprite_setTextureRect(ctr->player->spt, ctr->player->rect);
    sfRenderWindow_drawSprite(ctr->window, ctr->maps[ctr->m].spt, NULL);
    sfRenderWindow_drawSprite(ctr->window, ctr->player->spt, NULL);
    if (ctr->maps[ctr->m].spt2) {
        sfSprite_setPosition(ctr->maps[ctr->m].spt2, ctr->maps[ctr->m].pos);
        sfRenderWindow_drawSprite(ctr->window, ctr->maps[ctr->m].spt2, NULL);
    }
    loop_pause(ctr);
    sfRenderWindow_display(ctr->window);
}

void state_anim(ctr_t *ctr, int *n)
{
    *n += move_player_left(ctr);
    *n += move_player_right(ctr);
    *n += move_player_up(ctr);
    *n += move_player_down(ctr);
    change_map(ctr);
    if (*n == -4)
        ctr->player->rect.left = 0;
    sfSprite_setPosition(ctr->maps[ctr->m].spt, ctr->maps[ctr->m].pos);
    sfSprite_setPosition(ctr->player->spt, ctr->player->pos);
}

void movement_fight(ctr_t *ctr)
{
    int n = 0;
    int inventory_state = 0;

    ctr->state = 1;
    init_asset(ctr);
    init_rect(ctr);
    init_rect2(ctr);
    init_rect3(ctr);
    init_rect4(ctr);
    for (; sfRenderWindow_isOpen(ctr->window) && ctr->game_state != 1; n = 0) {
        poll_event_manager(ctr, &inventory_state);
        if (inventory_state)
            main_inventory(ctr, &inventory_state);
        state_anim(ctr, &n);
        draw_all(ctr);
    }
}
