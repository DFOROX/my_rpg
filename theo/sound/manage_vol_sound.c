/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** display menu state
*/

#include "../../my.h"

void set_volume_off(ctr_t *ctr)
{
    sfMusic_setVolume(ctr->obj[4].music, 0.0f);
    sfMusic_setVolume(ctr->obj[5].music, 0.0f);
    sfMusic_setVolume(ctr->obj[6].music, 0.0f);
}

void set_volume_on(ctr_t *ctr)
{
    sfMusic_setVolume(ctr->obj[4].music, 100.0f);
    sfMusic_setVolume(ctr->obj[5].music, 100.0f);
    sfMusic_setVolume(ctr->obj[6].music, 100.0f);
}

void set_volume(ctr_t *ctr, float vol)
{
    sfMusic_setVolume(ctr->obj[4].music, vol);
    sfMusic_setVolume(ctr->obj[5].music, vol);
    sfMusic_setVolume(ctr->obj[6].music, vol);
}
