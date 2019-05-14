/*
** EPITECH PROJECT, 2018
** get_item.c
** File description:
** get_item
*/

#include "../my.h"

int look_is_var(char **t, int i)
{
    for (; t[i] && !my_strcmpn("stat1", t[i]) && !my_strcmpn("stat2", \
    t[i]) && !my_strcmpn("texture", t[i]) && !my_strcmpn("text", t[i]) && \
    !my_strcmpn("id", t[i]) && !my_strcmpn("type", t[i]) && \
    !my_strcmpn("price", t[i]) && !my_strcmpn("name", t[i]) && \
    !my_strcmpn("lore", t[i]); i++);
    return (i);
}

int get_item3(ctr_t *ctr, char **t, int i, int m)
{
    int n = i;
    char *tmp = NULL;

    ctr->items[m].stat[0] = (my_strcmpn("stat1", t[i])) ? \
    my_getnbr(t[i + 1]) : ctr->items[m].stat[0];
    ctr->items[m].stat[1] = (my_strcmpn("stat2", t[i])) ? \
    my_getnbr(t[i + 1]) : ctr->items[m].stat[1];
    if (my_strcmpn("name", t[i]) || my_strcmpn("lore", t[i])) {
        n = look_is_var(t, i + 1) - 1;
        for (int j = i + 1; j <= n; j++)
            tmp = my_strcatn(tmp, my_strcatn(" ", t[j]));
        if (my_strcmpn("name", t[i]))
            ctr->items[m].name = tmp;
        else
            ctr->items[m].lore = tmp;
    }
    return (n);
}

void get_item2(ctr_t *ctr, char **t, int j)
{
    ctr->items[j] = (item_t) {0};
    for (int i = 0; t[i]; i += 1) {
        ctr->items[j].path = (my_strcmpn("texture", t[i]) || \
        my_strcmpn("text", t[i])) ? t[i += 1] : ctr->items[j].path;
        ctr->items[j].id = (my_strcmpn("id", t[i])) ? my_getnbr(t[i += 1]) : \
        ctr->items[j].id;
        ctr->items[j].type = (my_strcmpn("type", t[i])) ? \
        my_getnbr(t[i += 1]) : ctr->items[j].type;
        ctr->items[j].price = (my_strcmpn("price", t[i])) ? \
        my_getnbr(t[i += 1]) : ctr->items[j].price;
        i = get_item3(ctr, t, i, j);
    }
    ctr->items[j].text = sfTexture_createFromFile(ctr->items[j].path ? \
    ctr->items[j].path : "assets/bug.png", NULL);
    if (!ctr->items[j].text)
        ctr->items[j].text = sfTexture_createFromFile("assets/bug.png", NULL);
    ctr->items[j].spt = sfSprite_create();
    sfSprite_setTexture(ctr->items[j].spt, ctr->items[j].text, sfTrue);
}

void get_item(char *fd, ctr_t *ctr)
{
    char **file = my_str_to_word_array(read_file(fd), "\n");
    char **tmp;
    int i = 0;
    int j = 0;

    for (; file[i]; i += 1) {
        if (!is_item_name(file[i], "item"))
            continue;
        for (; file[i][j] && file[i][j] != '='; j += 1);
        tmp = my_str_to_word_array(file[i][j] && file[i][j + 1] == ' ' \
        ? file[i] + j + 1 : file[i] + j, ": ");
        get_item2(ctr, tmp, my_getnbr(file[i] + 4));
    }
}
