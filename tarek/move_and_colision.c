/*
** EPITECH PROJECT, 2019
** movement.c
** File description:
** tarek
*/

#include "tarek.h"

rect_t set_rect_player(ctr_t *ctr, int x, int y, map_t map)
{
    rect_t rect = {0};

    rect.a.x = ctr->player->pos.x + 64 / 4 + x - map.pos.x;
    rect.a.y = ctr->player->pos.y + 48 / 3 + y - map.pos.y;
    rect.b.x = ctr->player->pos.x + ((float)64 / 4) * 3 + x - map.pos.x;
    rect.b.y = ctr->player->pos.y + 48 / 4 + y - map.pos.y;
    rect.c.x = ctr->player->pos.x + ((float)64 / 4) * 3 + x - map.pos.x;
    rect.c.y = ctr->player->pos.y + ((float)48 / 3) * 3 + y - map.pos.y;
    rect.d.x = ctr->player->pos.x + 64 / 4 + x - map.pos.x;
    rect.d.y = ctr->player->pos.y + ((float)48 / 4) * 3 + y - map.pos.y;
    return (rect);
}

int move_player_up(ctr_t *ctr)
{
    rect_t rect = set_rect_player(ctr, 0, -6, ctr->maps[ctr->m]);

    if (sfKeyboard_isKeyPressed(sfKeyUp) && !check_colision(rect.a, \
    ctr->maps[ctr->m]) && !check_colision(rect.b, ctr->maps[ctr->m])) {
        ctr->player->rect.top = 192;
        if (ctr->maps[ctr->m].pos.y < 0 && ctr->player->pos.y <= SIZE_Y / 2)
            ctr->maps[ctr->m].pos.y += 3;
        else
            ctr->player->pos.y -= 3;
        spawn_fight(ctr);
        loop_anim_player(ctr);
        return (0);
    } else if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        check_colision(rect.b, ctr->maps[ctr->m]) > 1 ? \
        ctr->pnj[check_colision(rect.b, ctr->maps[ctr->m]) - 2](ctr) : 0;
        check_colision(rect.a, ctr->maps[ctr->m]) > 1 ? \
        ctr->pnj[check_colision(rect.a, ctr->maps[ctr->m]) - 2](ctr) : 0;
    }
    return (-1);
}

int move_player_down(ctr_t *ctr)
{
    rect_t rect = set_rect_player(ctr, 0, 6, ctr->maps[ctr->m]);
    int n = -(sfTexture_getSize(ctr->maps[ctr->m].text).y - SIZE_Y);

    if (sfKeyboard_isKeyPressed(sfKeyDown) && !check_colision(rect.c, \
    ctr->maps[ctr->m]) && !check_colision(rect.d, ctr->maps[ctr->m])) {
        ctr->player->rect.top = 0;
        if (ctr->maps[ctr->m].pos.y > n && ctr->player->pos.y >= SIZE_Y / 2)
            ctr->maps[ctr->m].pos.y -= 3;
        else
            ctr->player->pos.y += 3;
        spawn_fight(ctr);
        loop_anim_player(ctr);
        return (0);
    } else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        check_colision(rect.c, ctr->maps[ctr->m]) > 1 ?\
        ctr->pnj[check_colision(rect.c, ctr->maps[ctr->m]) - 2](ctr) : 0;
        check_colision(rect.d, ctr->maps[ctr->m]) > 1 ?\
        ctr->pnj[check_colision(rect.d, ctr->maps[ctr->m]) - 2](ctr) : 0;
    }
    return (-1);
}

int move_player_right(ctr_t *ctr)
{
    rect_t rect = set_rect_player(ctr, 6, 0, ctr->maps[ctr->m]);
    int n = -(sfTexture_getSize(ctr->maps[ctr->m].text).x - SIZE_X);

    if (sfKeyboard_isKeyPressed(sfKeyRight) && !check_colision(rect.b, \
    ctr->maps[ctr->m]) && !check_colision(rect.c, ctr->maps[ctr->m])) {
        ctr->player->rect.top = 128;
        if (ctr->maps[ctr->m].pos.x > n && ctr->player->pos.x >= SIZE_X / 2)
            ctr->maps[ctr->m].pos.x -= 3;
        else
            ctr->player->pos.x += 3;
        spawn_fight(ctr);
        loop_anim_player(ctr);
        return (0);
    } else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        check_colision(rect.b, ctr->maps[ctr->m]) > 1 ?\
        ctr->pnj[check_colision(rect.b, ctr->maps[ctr->m]) - 2](ctr) : 0;
        check_colision(rect.c, ctr->maps[ctr->m]) > 1 ?\
        ctr->pnj[check_colision(rect.c, ctr->maps[ctr->m]) - 2](ctr) : 0;
    }
    return (-1);
}

int move_player_left(ctr_t *ctr)
{
    rect_t rect = set_rect_player(ctr, -6, 0, ctr->maps[ctr->m]);

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && !check_colision(rect.a, \
    ctr->maps[ctr->m]) && !check_colision(rect.d, ctr->maps[ctr->m])) {
        ctr->player->rect.top = 64;
        if (ctr->maps[ctr->m].pos.x < 0 && ctr->player->pos.x <= SIZE_X / 2)
            ctr->maps[ctr->m].pos.x += 3;
        else
            ctr->player->pos.x -= 3;
        spawn_fight(ctr);
        loop_anim_player(ctr);
        return (0);
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        check_colision(rect.d, ctr->maps[ctr->m]) > 1 ?\
        ctr->pnj[check_colision(rect.d, ctr->maps[ctr->m]) - 2](ctr) : 0;
        check_colision(rect.a, ctr->maps[ctr->m]) > 1 ?\
        ctr->pnj[check_colision(rect.a, ctr->maps[ctr->m]) - 2](ctr) : 0;
    }
    return (-1);
}
