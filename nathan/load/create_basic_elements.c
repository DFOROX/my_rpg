/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_create.c
*/

#include "../my.h"

sfRenderWindow *create_window(char *name, char *fd)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = SIZE_X;
    video_mode.height = SIZE_Y;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, name, sfClose, NULL);
    if (fd)
        sfRenderWindow_setIcon(window, 100, 100, \
        sfImage_getPixelsPtr(sfImage_createFromFile(fd)));
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

obj_t create_obj(char *fd, sfVector2f pos, sfIntRect r, int id)
{
    obj_t obj = {0};

    obj.id = id;
    obj.v2f = pos;
    if (id == 1) {
        obj.texture = sfTexture_createFromFile(fd ? fd : \
        "assets/bug.png", NULL);
        obj.rect = (!r.width || !r.height) ? (sfIntRect) {0, 0,
        sfTexture_getSize(obj.texture).x, sfTexture_getSize(obj.texture).y} : r;
        obj.spt = sfSprite_create();
        sfSprite_setTexture(obj.spt, obj.texture, sfTrue);
        sfSprite_setTextureRect(obj.spt, obj.rect);
        sfSprite_setPosition(obj.spt, obj.v2f);
    }
    obj.texture = id != 1 ? NULL : obj.texture;
    obj.spt = id != 1 ? NULL : obj.spt;
    obj.music = fd && id == 2 ? sfMusic_createFromFile(fd) : NULL;
    obj.font = fd && id == 3 ? sfFont_createFromFile (fd) : NULL;
    return (obj);
}
