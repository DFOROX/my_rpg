/*
** EPITECH PROJECT, 2019
** hit
** File description:
** hit
*/

#include "tarek.h"

void display_anim(ctr_t *data, monster_t *monsters, int a, int b)
{
    sfRenderWindow_clear(data->window, sfBlack);
    manage_anim_mstr(data);
    sfText_setString(data->obj[11].txt, my_itoa_static(data->player->life));
    sfText_setPosition(data->obj[11].txt, (sfVector2f){304, 869});
    sfText_setString(data->obj[15].txt, my_itoa_static(data->player->hp_max));
    sfText_setPosition(data->obj[15].txt, (sfVector2f){390, 869});
    sfSprite_setPosition(data->obj[44].spt, (sfVector2f){255, 850});
    if (data->state == 4)
        sfRenderWindow_drawSprite(data->window, data->obj[46].spt, NULL);
    else
        sfRenderWindow_drawSprite(data->window, data->obj[11].spt, NULL);
    sfRenderWindow_drawSprite(data->window, data->obj[13].spt, NULL);
    sfRenderWindow_drawText(data->window, data->obj[11].txt, NULL);
    sfRenderWindow_drawText(data->window, data->obj[15].txt, NULL);
    print_spt(data, monsters);
    set_monster_state(data, monsters);
    draw_anim(data, monsters, a, b);
    sfRenderWindow_display(data->window);
}

monster_t *hit_zone(int p[2], ctr_t *d, monster_t *m)
{
    float a;

    d->obj[43].rect.left = 0;
    if (p[0] == 1 && !p[1])
        while (d->obj[43].rect.left <= 447)
            display_anim(d, m, 0, 1);
    for (int i = 0; i < 3; i++) {
        a = 3 * d->player->stat[p[1]] / (float)m[i].res[p[1]];
        m[i].pv -= a;
        m[i].pv -= (a > (int)a) ? 1 : 0;
    }
    return (m);
}

void get_bonus(int p[2], ctr_t *data, monster_t *m)
{
    data->obj[44].rect.left = 0;
    data->obj[48].rect.left = 0;
    if (p[1] == 0)
        data->player->life += data->player->stat[0];
    if (data->player->life > data->player->hp_max)
        data->player->life = data->player->hp_max;
    if (p[1] == 1) {
        data->player->boost = 2;
        data->player->stat[1] += 15;
    }
    if (p[0] == 2 && !p[1])
        while (data->obj[44].rect.left <= 3474)
            display_anim(data, m, 0, 2);
    if (p[0] == 2 && p[1] == 1)
        while (data->obj[48].rect.left <= 3474)
            display_anim(data, m, 0, 3);
}

monster_t *hard_hit(int p[2], ctr_t *data, monster_t *m, int i)
{
    float a = data->player->stat[p[1]] * 100 / m[i].res[p[1]];

    data->obj[15].rect.left = 0;
    data->obj[49].rect.left = 0;
    if (p[0] == 3 && !p[1])
        while (data->obj[15].rect.left <= 545)
            display_anim(data, m, 2, 0);
    if (p[0] == 3 && p[1] == 1) {
        while (data->obj[49].rect.left <= 800)
            display_anim(data, m, 4, 0);
    }
    m[i].pv -= a;
    if ((int)a < a)
        m[i].pv--;
    data->player->life -= m[i].res[p[1]];
    return (m);
}

void dgt(ctr_t *data, monster_t m)
{
    float ans = ((rand() % (1 + m.dgt_max - m.dgt_min)) + m.dgt_min) /
    ((float)data->inv_it[1]->stat[m.type] +
    (float)data->inv_it[0]->stat[m.type]);
    data->player->life -= (int)ans;
    if ((int)ans < ans)
        data->player->life--;
}
