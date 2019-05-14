/*
** EPITECH PROJECT, 2019
** init_fight
** File description:
** init_fight
*/

#include "tarek.h"

char *stupid(char *str)
{
    return (str);
}

monster_t init_monster4(int val)
{
    monster_t new;

    new.type = val;
    new.xp = 100;
    new.loot = 0;
    new.pv = new.type ? 50 : 30;
    new.res[0] = new.type ? 20 : 30;
    new.res[1] = new.type ? 40 : 10;
    new.dgt_max = new.type ? 60 : 100;
    new.dgt_min = new.type ? 20 : 50;
    new.speed = new.type ? 60 : 70;
    new.name = stupid(new.type ? "soldat" : "mage");
    return (new);
}

monster_t init_monster3(int val)
{
    monster_t new;

    new.type = val;
    new.xp = new.type ? 20 : 15;
    new.loot = rand() % 90 + 10;
    new.pv = 20;
    new.res[0] = new.type ? 3 : 7;
    new.res[1] = new.type ? 7 : 4;
    new.dgt_max = new.type ? 10 : 15;
    new.dgt_min = new.type ? 7 : 3;
    new.speed = new.type ? 30 : 40;
    new.name = stupid(new.type ? "gobelin" : "chamane");
    return (new);
}

monster_t init_monster1(int val)
{
    monster_t new;

    new.type = val;
    new.xp = 5;
    new.loot = rand() % 4;
    new.pv = 5;
    new.res[0] = new.type ? 1 : 3;
    new.res[1] = new.type ? 5 : 1;
    new.dgt_max = new.type ? 1 : 3;
    new.dgt_min = new.type ? 1 : 0;
    new.speed = 100;
    new.name = stupid(new.type ? "rat" : "wisp");
    return (new);
}

monster_t *create_monsters(ctr_t *data)
{
    monster_t *monsters = malloc(sizeof(monster_t) * 4);
    int i = 1;

    init_pos_icone(data);
    monsters[0] = data->init_monster[data->state - 1](rand() % 2);
    for (; i < 3 && rand() % 3; i++)
        monsters[i] = data->init_monster[data->state - 1](rand() % 2);
    for (; i < 3; i++) {
        monsters[i] = data->init_monster[3](1);
        monsters[i].pv = 0;
        monsters[i].xp = 0;
        monsters[i].loot = 0;
    }
    init_vect_mstr(monsters);
    return (monsters);
}