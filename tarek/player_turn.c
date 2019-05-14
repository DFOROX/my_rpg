/*
** EPITECH PROJECT, 2019
** player_turn
** File description:
** player_turn
*/

#include "tarek.h"

void set_pos_tab3(monster_t *monsters, ctr_t *data, int index, int index2);

int key(int k)
{
    if (!KEY(k))
        return (0);
    while (KEY(k));
    return (1);
}

void display(ctr_t *data, monster_t *monsters)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfText_setString(data->obj[11].txt, my_itoa_static(data->player->life));
    sfText_setPosition(data->obj[11].txt, (sfVector2f){304, 869});
    sfText_setString(data->obj[15].txt, my_itoa_static(data->player->hp_max));
    sfText_setPosition(data->obj[15].txt, (sfVector2f){390, 869});
    if (data->state == 4)
        sfRenderWindow_drawSprite(data->window, data->obj[46].spt, NULL);
    else
        sfRenderWindow_drawSprite(data->window, data->obj[11].spt, NULL);
    sfRenderWindow_drawSprite(data->window, data->obj[13].spt, NULL);
    sfRenderWindow_drawText(data->window, data->obj[11].txt, NULL);
    sfRenderWindow_drawText(data->window, data->obj[15].txt, NULL);
    set_monster_state(data, monsters);
    print_spt(data, monsters);
    sfRenderWindow_display(data->window);
}

monster_t *hit(int p[2], ctr_t *d, monster_t *m, int i)
{
    float dgt;

    d->player->stat[2] -= d->player->boost == 1 ? 15 : 0;
    d->player->boost -= d->player->boost ? 1 : 0;
    if (p[0] == 0) {
        dgt = ((rand() % (d->inv_it[2]->stat[1] - d->inv_it[2]->stat[0]) +
        d->inv_it[2]->stat[0]) * d->player->stat[d->inv_it[2]->type]) /
        (float)m[i].res[d->inv_it[2]->type];
        m[i].pv -= (int)dgt;
        if ((int)dgt < dgt)
            m[i].pv--;
    }
    if (p[0] == 1)
        return (hit_zone(p, d, m));
    if (p[0] == 2)
        get_bonus(p, d, m);
    if (p[0] == 3)
        return (hard_hit(p, d, m, i));
    return (m);
}

monster_t *choose_cible(int p[2], ctr_t *data, monster_t *monsters, int i)
{
    int j;

    for (; i < 2 && monsters[i].pv <= 0; i++);
    j = i;
    for (;!key(sfKeySpace) && p[0] != 1 && p[0] != 2; i = j) {
        j = (key(sfKeyUp)) ? j - 1 : j;
        if (j >= 0 && monsters[j].pv <= 0)
            j--;
        j = (j < 0 || monsters[j].pv <= 0) ? i : j;
        if (key(sfKeyDown))
            j++;
        if (j <= 2 && monsters[j].pv <= 0)
            j++;
        if (j > 2 || monsters[j].pv <= 0)
            j = i;
        choose_cible2(data, monsters, i);
    }
    set_pos_compt(data, j);
    return (hit(p, data, monsters, i));
}

monster_t *p_turn(ctr_t *d, monster_t *m)
{
    int p[2] = {0, 0};

    while (!key(sfKeySpace)) {
        select_comp(d, p, m);
        if (p[1] > 0 && d->player->cpt / 4 >= p[0] && key(sfKeyUp))
            p[1]--;
        if (p[1] < 1 && d->player->cpt % 4 >= p[0] && key(sfKeyDown))
            p[1]++;
        if (p[0] > 0 && key(sfKeyLeft))
            p[0]--;
        if ((!p[1] || !p[0]) && d->player->cpt / 4 > p[0] && key(sfKeyRight)) {
            p[0]++;
            p[1] = 0;
        }
        if ((p[1] || !p[0]) && d->player->cpt % 4 > p[0] && key(sfKeyRight)) {
            p[0]++;
            p[1] = 1; }
    }
    return (choose_cible(p, d, m, 0));
}
