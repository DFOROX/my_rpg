/*
** EPITECH PROJECT, 2019
** pause_init.c
** File description:
** catch event from mouse button
*/

#include "pause.h"

void close_event_pause(ctr_t *ctr)
{
    while (sfRenderWindow_pollEvent(ctr->window, &ctr->event))
        if (ctr->event.type == sfEvtClosed)
            sfRenderWindow_close(ctr->window);
}

void play_pause_music(ctr_t *ctr, int n, int test)
{
    static int m = -1;

    if (m != n) {
        m = n;
        if (test)
            sfMusic_play(ctr->obj[5].music);
    }
}

int event_pause_bis(ctr_t *ctr, button_t *pause_button, int n)
{
    if (n == 2 && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_play(ctr->obj[6].music);
        while (sfMouse_isButtonPressed(sfMouseLeft))
            display_pause_button(ctr, pause_button);
        ctr->game_state = 1;
        return (1);
    }
    if (n == 3 && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_play(ctr->obj[6].music);
        while (sfMouse_isButtonPressed(sfMouseLeft))
            display_pause_button(ctr, pause_button);
        sfRenderWindow_close(ctr->window);
        return (1);
    }
    return (0);
}

int event_pause(ctr_t *ctr, button_t *pause_button, int n)
{
    if (n == 0 && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_play(ctr->obj[6].music);
        while (sfMouse_isButtonPressed(sfMouseLeft))
            display_pause_button(ctr, pause_button);
        return (1);
    }
    if (n == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_play(ctr->obj[6].music);
        while (sfMouse_isButtonPressed(sfMouseLeft))
            display_pause_button(ctr, pause_button);
        save_ctr(ctr, "assets/save/my_save");
        return (1);
    }
    return (event_pause_bis(ctr, pause_button, n));
}

int button_event_pause(ctr_t *ctr, button_t *pause_button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(ctr->window);
    int button_test = 0;
    int test = 1;

    for (int i = 0; i < NB_PAUSE_BUTTON; i++) {
        if (pause_button[i].pos3.x < mouse.x && pause_button[i].pos3.x + 7 * \
        CHAR_PAUSE_SIZE > mouse.x && pause_button[i].pos3.y < mouse.y && \
        pause_button[i].pos3.y + CHAR_PAUSE_SIZE > mouse.y) {
            play_pause_music(ctr, i, 1);
            test = 0;
            button_test += event_pause(ctr, pause_button, i);
        }
    }
    if (test == 1)
        play_pause_music(ctr, -1, 0);
    return (button_test);
}
