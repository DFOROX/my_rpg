/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "../my.h"

void create_ctr(ctr_t *ctr)
{
    sfTexture *text = sfTexture_createFromFile("assets/loading.png", NULL);
    sfSprite *spt = sfSprite_create();

    sfSprite_setTexture(spt, text, sfTrue);
    sfSprite_setPosition(spt, (sfVector2f) {SIZE_X / 2 - 240, SIZE_Y / 2 - 70});
    ctr->window = create_window("My Rpg", NULL);
    sfRenderWindow_drawSprite(ctr->window, spt, NULL);
    sfRenderWindow_display(ctr->window);
    srand((long)ctr);
    get_item(PATH_ITEM, ctr);
    get_map(ctr);
    get_obj(ctr);
    sfTexture_destroy(text);
    sfSprite_destroy(spt);
}

void load_ctr(ctr_t *ctr, char *path)
{
    char *tmp = read_file(path ? path : PATH_DEFAULT);
    char **tmp2 = my_str_to_word_array(tmp, "\n");
    int i = 0;
    int j = 6;

    get_inv(tmp2, ctr);
    get_player(ctr, tmp2);
    for (; tmp2[i] && !is_var_name(tmp2[i], "map", '='); i += 1);
    ctr->m = tmp2[i] ? my_getnbr(tmp2[i] + 6) : 0;
    if (!tmp2[i])
        return;
    for (; tmp2[i][j] != ' ' && tmp2[i][j]; j++);
    ctr->maps[ctr->m].pos.x = my_getnbr(tmp2[i] + j + 1);
    for (j = j + 1; tmp2[i][j] != ' ' && tmp2[i][j]; j++);
    ctr->maps[ctr->m].pos.y = my_getnbr(tmp2[i] + j + 1);
}
