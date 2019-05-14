/*
** EPITECH PROJECT, 2018
** get_item.c
** File description:
** get_item
*/

#include "../my.h"

item_t *get_inv2(ctr_t *ctr, int id)
{
    int i = 0;

    for (; i < NB_ITEM && ctr->items[i].id != id; i++);
    if (i < NB_ITEM)
        return (&ctr->items[i]);
    else
        return (NULL);
}

void get_inv(char **file, ctr_t *ctr)
{
    char **tmp;
    int i = 0;
    int j = 0;

    for (; file[i]; i += 1) {
        if (!is_var_name(file[i], "items", '='))
            continue;
        for (; file[i][j] && file[i][j] != '='; j += 1);
        tmp = my_str_to_word_array(file[i][j] && file[i][j + 1] == ' ' \
        ? file[i] + j + 1 : file[i] + j, " ");
        for (int k = 0; tmp[k] && k < NB_INV; k++) {
            ctr->inv_it[k] = get_inv2(ctr, my_getnbr(tmp[k]));
        }
    }
}
