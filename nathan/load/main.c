/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "../my.h"

void my_test_load(void)
{
    ctr_t ctr;

    create_ctr(&ctr);
    load_ctr(&ctr, "resource/save");
    while (sfRenderWindow_isOpen(ctr.window)) {
    sfRenderWindow_pollEvent(ctr.window, &ctr.event);
        if (ctr.event.type == sfEvtClosed || \
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(ctr.window);
        sfRenderWindow_display(ctr.window);
        sfRenderWindow_clear(ctr.window, sfBlack);
        sfRenderWindow_drawSprite(ctr.window, ctr.obj[1].spt, NULL);
    }
    save_ctr(ctr, "resource/save");
    destroy_player(ctr.player);
}

void my_test_file(void)
{
    char **save = get_save("resource");

    for (int i = 0; save[i]; i++) {
        my_putstr_fd(1, save[i]);
        write(1, "\n", 1);
    }
    free(save);
}

int main(void)
{
    my_test_load();
    return (0);
}
