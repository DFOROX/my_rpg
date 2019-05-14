/*
** EPITECH PROJECT, 2019
** menu.h
** File description:
** menu header file
*/

#ifndef MENU_H_
#define MENU_H_

#ifndef MY_H_
#include "../../my.h"
#endif

#define SAVE_PATH "assets/save/"
#define BUT_S 6
#define BUT_S_L (BUT_S - 1)

typedef struct button_s
{
    char str[16];
    sfText *txt;
    int s_txt;
    sfColor color[3];
    sfVector2i pos1;
    sfVector2i pos2;
    sfVector2f pos3;
    int state;
} button_t;

typedef struct menu_s
{
    int me_st;
    sfMusic *music;
    int nb_save;
    char **tmp;
    char htp_str[512];
    sfText *htp_txt;
} menu_t;

button_t *create_save_button(ctr_t *, menu_t *);
void fill_button_array(ctr_t *, button_t **);
void init_sound_button(ctr_t *);
void menu_init_how_play(ctr_t *, menu_t *);
void clean_menu(button_t **, menu_t *, button_t *);
void sf_poll_event(ctr_t *, button_t **, menu_t *, button_t *);
void menu_mouse_event(ctr_t *, button_t **, menu_t *, button_t *);
void menu_button(ctr_t *, button_t **, menu_t *, button_t *);

#endif
