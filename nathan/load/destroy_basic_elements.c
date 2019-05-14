/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_create.c
*/

#include "../my.h"

void destroy_obj(obj_t obj)
{
    if (obj.id == 1) {
        sfSprite_destroy(obj.spt);
        sfTexture_destroy(obj.texture);
    }
    if (obj.id == 2)
        sfMusic_destroy(obj.music);
    if (obj.id == 3)
        sfFont_destroy(obj.font);
}

void destroy_item(item_t item)
{
    if (item.spt)
        sfSprite_destroy(item.spt);
    if (item.text)
        sfTexture_destroy(item.text);
    if (item.name)
        free(item.name);
    if (item.lore)
        free(item.lore);
    if (item.path)
        free(item.path);
}

void destroy_map(map_t map)
{
    if (map.text)
        sfTexture_destroy(map.text);
    if (map.text2)
        sfTexture_destroy(map.text2);
    if (map.spt)
        sfSprite_destroy(map.spt);
    if (map.spt2)
        sfSprite_destroy(map.spt2);
}

void destroy_game(ctr_t *ctr)
{
    sfRenderWindow_destroy(ctr->window);
    if (ctr->player) {
        sfSprite_destroy(ctr->player->spt);
        sfTexture_destroy(ctr->player->text);
        sfClock_destroy(ctr->player->clock);
        if (ctr->player->path)
            free(ctr->player->path);
        free(ctr->player);
    }
    for (int i = 0; i < NB_OBJ; i++)
        destroy_obj(ctr->obj[i]);
    for (int i = 0; i < NB_ITEM; i++)
        destroy_item(ctr->items[i]);
    for (int i = 0; i < NB_MAP; i++)
        destroy_map(ctr->maps[i]);
}
