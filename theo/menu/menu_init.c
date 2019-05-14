/*
** EPITECH PROJECT, 2019
** menu_init.c
** File description:
** init and create all menu items
*/

#include "menu.h"

void set_default_val(button_t *button, int i, int x_pos, int x_len)
{
    sfVector2f pos = {x_pos, 72 * (i + 1) + 172};

    button->s_txt = 42;
    button->color[0] = (sfColor){200, 200, 200, 255};
    button->color[1] = (sfColor){255, 255, 255, 255};
    button->color[2] = (sfColor){255, 255, 0, 192};
    button->pos1 = (sfVector2i){x_pos, 72 * (i + 1) + 172};
    button->pos2 = (sfVector2i){x_pos + x_len, \
    button->pos1.y + 42};
    button->pos3 = pos;
    button->state = 0;
}

void fill_button_array(ctr_t *ctr, button_t **button)
{
    char *str[] = {"NEW GAME", "LOAD", "OPTIONS", "HOW TO PLAY", "EXIT", \
    "RISE OF AEJORN"};

    for (int i = 0; i != BUT_S; ++i) {
        (*button)[i].txt = sfText_create();
        my_strcpy((*button)[i].str, str[i]);
        if (i != BUT_S_L) {
            set_default_val((*button) + i, i, 128, 42 * 6);
            sfText_setFont((*button)[i].txt, ctr->obj[2].font);
            sfText_setCharacterSize((*button)[i].txt, 42);
            sfText_setColor((*button)[i].txt, (*button)[i].color[0]);
        } else {
            sfText_setFont((*button)[i].txt, ctr->obj[3].font);
            sfText_setCharacterSize((*button)[i].txt, 96);
            (*button)[i].pos3 = (sfVector2f){72, 96};
        }
        sfText_setString((*button)[i].txt, (*button)[i].str);
        sfText_setPosition((*button)[i].txt, (*button)[i].pos3);
    }
}

button_t *init_no_save_text(ctr_t *ctr)
{
    button_t *new = malloc(sizeof(button_t));

    if (!new)
        return (NULL);
    new->txt = sfText_create();
    my_strcpy(new->str, "NO SAVES FOUND");
    set_default_val(new, 1, 750, 3 * 42);
    sfText_setFont(new->txt, ctr->obj[2].font);
    sfText_setCharacterSize(new->txt, 42);
    sfText_setColor(new->txt, new->color[0]);
    sfText_setString(new->txt, new->str);
    sfText_setPosition(new->txt, new->pos3);
    return (new);
}

button_t *create_save_button(ctr_t *ctr, menu_t *menu)
{
    button_t *new = NULL;

    menu->tmp = get_save(SAVE_PATH);
    for (; menu->tmp && menu->tmp[menu->nb_save]; ++menu->nb_save);
    if (!menu->nb_save)
        return (init_no_save_text(ctr));
    new = malloc(sizeof(button_t) * menu->nb_save);
    if (!new)
        return (NULL);
    for (int i = 0; i != menu->nb_save; ++i) {
        new[i].txt = sfText_create();
        my_strcpy(new[i].str, menu->tmp[i]);
        set_default_val(new + i, i, 750, 3 * 42);
        sfText_setFont(new[i].txt, ctr->obj[2].font);
        sfText_setCharacterSize(new[i].txt, 42);
        sfText_setColor(new[i].txt, new[i].color[1]);
        sfText_setString(new[i].txt, new[i].str);
        sfText_setPosition(new[i].txt, new[i].pos3);
    }
    return (new);
}

void init_sound_button(ctr_t *ctr)
{
    ctr->obj[8].rect.top = 0;
    ctr->obj[8].rect.left = 0;
    ctr->obj[8].rect.width = 135;
    ctr->obj[8].rect.height = 105;
    ctr->obj[8].v2f.x = 893.0f;
    ctr->obj[8].v2f.y = 488.0f;
    sfSprite_setTextureRect(ctr->obj[8].spt, ctr->obj[8].rect);
    sfSprite_setPosition(ctr->obj[8].spt, ctr->obj[8].v2f);
}
