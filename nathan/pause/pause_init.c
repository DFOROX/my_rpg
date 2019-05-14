/*
** EPITECH PROJECT, 2019
** pause_init.c
** File description:
** init and create all pause items
*/

#include "pause.h"

button_t *create_pause_button(ctr_t *ctr)
{
    button_t *pause_button = malloc(sizeof(button_t) * NB_PAUSE_BUTTON);
    char text_buuton[NB_PAUSE_BUTTON][16] = {"\tResume", "\t   Save", \
    "\t   Menu", "\t   Exit"};

    for (int i = 0; i < NB_PAUSE_BUTTON; i++) {
        pause_button[i] = (button_t) {0};
        my_strcpy(pause_button[i].str, text_buuton[i]);
        pause_button[i].color[0] = (sfColor){0, 0, 0, 255};
        pause_button[i].color[1] = (sfColor){100, 100, 100, 255};
        pause_button[i].color[2] = (sfColor){255, 255, 0, 192};
        pause_button[i].pos3 = (sfVector2f) {SIZE_X / 2 - 3 * \
        CHAR_PAUSE_SIZE, 300 + i * (CHAR_PAUSE_SIZE + 40)};
        pause_button[i].txt = sfText_create();
        sfText_setFont(pause_button[i].txt, ctr->obj[2].font);
        sfText_setCharacterSize(pause_button[i].txt, CHAR_PAUSE_SIZE);
        sfText_setColor(pause_button[i].txt, pause_button[i].color[0]);
        sfText_setString(pause_button[i].txt, pause_button[i].str);
        sfText_setPosition(pause_button[i].txt, pause_button[i].pos3);
    }
    return (pause_button);
}
