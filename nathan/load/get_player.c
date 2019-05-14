/*
** EPITECH PROJECT, 2018
** get_var_name.c
** File description:
** get_var_name
*/

#include "../my.h"

int get_player5(player_t *p, char **t, int i)
{
    if (!my_strcmpn("map", t[i]))
        return (i);
    i += 1;
    p->pos_map.x = (t[i]) ? my_getnbr(t[i]) : 0;
    i += (t[i]) ? 1 : 0;
    p->pos_map.y = (t[i]) ? my_getnbr(t[i]) : 0;
    i += (t[i]) ? 1 : 0;
    return (i - 1);
}

int get_player4(player_t *p, char **t, int i)
{
    if (!my_strcmpn("rect", t[i]))
        return (i);
    i += 1;
    p->rect.top = (t[i]) ? my_getnbr(t[i]) : 0;
    i += (t[i]) ? 1 : 0;
    p->rect.left = (t[i]) ? my_getnbr(t[i]) : 0;
    i += (t[i]) ? 1 : 0;
    p->rect.width = (t[i]) ? my_getnbr(t[i]) : 0;
    i += (t[i]) ? 1 : 0;
    p->rect.height = (t[i]) ? my_getnbr(t[i]) : 0;
    i += (t[i]) ? 1 : 0;
    return (get_player5(p, t, i - 1));
}

int get_player3(player_t *p, char **t, int i)
{
    p->lvl = (my_strcmpn("lvl", t[i]) || my_strcmpn("level", t[i])) ? \
    my_getnbr(t[i + 1]) : p->lvl;
    p->stat[0] = (my_strcmpn("strength", t[i])) ? \
    my_getnbr(t[i + 1]) : p->stat[0];
    p->stat[1] = (my_strcmpn("intelligence", t[i])) ? \
    my_getnbr(t[i + 1]) : p->stat[1];
    p->speed = (my_strcmpn("speed", t[i])) \
    ? my_getnbr(t[i + 1]) : p->speed;
    p->cpt = (my_strcmpn("competencies", t[i]) || \
    my_strcmpn("cpt", t[i])) ? my_getnbr(t[i + 1]) : p->cpt;
    p->cpt_nb = (my_strcmpn("competencies_nb", t[i]) || \
    my_strcmpn("cpt", t[i])) ? my_getnbr(t[i + 1]) : p->cpt_nb;
    p->quete_state = (my_strcmpn("quete_state", t[i]) || \
    my_strcmpn("quete", t[i])) ? my_getnbr(t[i + 1]) : p->quete_state;
    p->hp_max = (my_strcmpn("hp_max", t[i])) ? my_getnbr(t[i + 1]) : p->hp_max;
    return (get_player4(p, t, i));
}

void get_player2(player_t *p, char **t)
{
    p->path = NULL;
    for (int i = 0; t[i]; i += 1) {
        p->pos.x = (my_strcmpn("x", t[i])) ? my_getnbr(t[i += 1]) : p->pos.x;
        p->pos.y = (my_strcmpn("y", t[i])) ? my_getnbr(t[i += 1]) : p->pos.y;
        p->path = (my_strcmpn("texture", t[i]) || my_strcmpn("text", t[i])) ? \
        t[i += 1] : p->path;
        p->life = (my_strcmpn("life", t[i])) ? my_getnbr(t[i += 1]) : p->life;
        p->xp = (my_strcmpn("xp", t[i])) ? my_getnbr(t[i += 1]) : p->xp;
        p->gold = (my_strcmpn("gold", t[i])) ? my_getnbr(t[i += 1]) : p->gold;
        i = get_player3(p, t, i);
    }
    p->text = sfTexture_createFromFile(p->path ? p->path : \
    "assets/bug.png", NULL);
    if (!p->text)
        p->text = sfTexture_createFromFile("assets/bug.png", NULL);
    p->spt = sfSprite_create();
    sfSprite_setTexture(p->spt, p->text, sfTrue);
    sfSprite_setTextureRect(p->spt, p->rect);
    p->clock = sfClock_create();
}

void get_player(ctr_t *ctr, char **file)
{
    char **tmp;
    int i = 0;
    int j = 0;

    ctr->player = malloc(sizeof(player_t));
    *ctr->player = (player_t) {0};
    ctr->player->rect = (sfIntRect) {0, 0, 50, 50};
    for (; file[i] && !is_var_name(file[i], "player", '='); i += 1);
    if (!is_var_name(file[i], "player", '='))
        return;
    for (; file[i][j] && file[i][j] != '='; j += 1);
    tmp = my_str_to_word_array(file[i][j] && file[i][j + 1] == ' ' ? file[i] + \
    j + 1 : file[i] + j, ": ");
    get_player2(ctr->player, tmp);
    ctr->player->lvl += (ctr->player->lvl == 0) ? 1 : 0;
}
