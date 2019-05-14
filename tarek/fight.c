/*
** EPITECH PROJECT, 2019
** fight
** File description:
** fight
*/

#include "tarek.h"

void anim_fight(ctr_t *data, monster_t *m, int timer)
{
    if ((timer % m[0].speed == 0 && m[0].pv > 0) || \
    (timer % m[1].speed == 0 && m[1].pv > 0) || \
    (timer % m[2].speed == 0 && m[2].pv > 0)) {
        data->obj[16].rect.left = 0;
        data->obj[17].rect.left = 0;
        data->obj[18].rect.left = 0;
        data->obj[19].rect.left = 0;
        data->obj[47].rect.left = 0;
        data->obj[50].rect.left = 0;
        data->obj[47].rect.top = 47;
        data->obj[16].rect.top = 192;
        data->obj[17].rect.top = 120;
        data->obj[18].rect.top = 186;
        data->obj[19].rect.top = 146;
        data->obj[45].rect.top = 105;
        data->obj[50].rect.top = 101;
    }
    display_anim(data, m, 0, 0);
}

char *my_itoa(int nb)
{
    int a = nb;
    int b = 0;
    int c = 1;
    int i = 0;
    char *str;

    for (; a > 0; i++) {
        a /= 10;
        c *= 10;
    }
    str = malloc(i + 1);
    str[i] = 0;
    c /= 10;
    for (i = 0; c >= 1; i++) {
        str[i] = (nb / c) - (b * 10) + 48;
        b *= 10;
        b += str[i] - 48;
        c /= 10;
    }
    return ((nb <= 0) ? "0" : str);
}

monster_t *heal(monster_t *monsters)
{
    if (monsters[0].pv > monsters[1].pv)
        monsters[1].pv = 50;
    else
        monsters[0].pv = 50;
    return (monsters);
}

void fight_loop(monster_t *m, ctr_t *d)
{
    int timer = 0;

    sfMusic_play(d->obj[39].music);
    while (d->player->life > 0 && (m[0].pv > 0 || m[1].pv > 0 ||
    m[2].pv > 0)) {
        timer++;
        if (timer == d->player->speed * m[0].speed * m[1].speed * m[2].speed)
            timer = 0;
        m = (timer % d->player->speed == 0) ? p_turn(d, m) : m;
        anim_fight(d, m, timer);
        for (int i = 0; i < 3; i++)
            if (timer % m[i].speed == 0 && m[i].type < 2 && m[i].pv > 0)
                dgt(d, m[i]);
            else if (timer % m[i].speed == 0 && m[i].pv > 0)
                m = heal(m);
        display_anim(d, m, 0, 0); }
        for (int i = 0; i < 3; i++) {
            d->player->xp += m[i].xp;
            d->player->gold += m[i].loot;
    }
    sfMusic_stop(d->obj[39].music);
}

void fight(ctr_t *data)
{
    monster_t *monsters;

    monsters = create_monsters(data);
    fight_loop(monsters, data);
    if (data->player->life <= 0)
        data->game_state = 1;
    else
        update_level(data);
}
