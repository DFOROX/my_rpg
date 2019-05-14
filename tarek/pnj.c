/*
** EPITECH PROJECT, 2019
** pnj
** File description:
** pnj
*/

#include "tarek.h"

void draw_text(char *str, ctr_t *data)
{
    sfText *txt = sfText_create();

    sfSprite_setPosition(data->obj[41].spt, (sfVector2f){180, 900});
    sfRenderWindow_drawSprite(data->window, data->obj[41].spt, NULL);
    sfText_setString(txt, str);
    sfText_setFont(txt, data->obj[7].font);
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, (sfVector2f){200, 920});
    sfRenderWindow_drawText(data->window, txt, NULL);
    sfRenderWindow_display(data->window);
    while (!sfKeyboard_isKeyPressed(sfKeySpace) && \
    sfRenderWindow_isOpen(data->window));
    sfText_destroy(txt);
}

void farmer(ctr_t *data)
{
    if (data->player->quete_state == 0) {
        data->player->quete_state = 1;
        draw_text("Lord Armolte killed your dog, Fluffy.\nThat naughty!", data);
    } else
        draw_text("Please, don't go to his castle to get revenge.", data);
}

void guard(ctr_t *data)
{
    if (data->player->quete_state < 4 && data->player->quete_state > 2) {
        draw_text("Did you rescue my daughter?", data);
    }
    if (data->player->quete_state > 4) {
        draw_text("Thank you very much.", data);
    }
    if (data->player->quete_state == 2) {
        data->player->quete_state = 3;
        draw_text("Oh my god, goblins came from the forest to kidnape my dau"\
        "ghter and i have to stay here!\nPlease, could you save her?", data);
    } else if (data->player->quete_state == 4) {
        data->player->quete_state = 5;
        draw_text("Thank you stranger, here is the key of the castle i have"\
        "to protect.\nI know, I am the worst guard of the kingdom but you "\
        "deserve it, my friend.", data);
    }
}

void gate(ctr_t *data)
{
    if (data->player->quete_state == 1)
        data->player->quete_state = 2;
    if (data->player->quete_state == 5) {
        data->m = 4;
        data->maps[4].pos.x = -1260;
        data->maps[4].pos.y = -2120;
        data->player->pos.x = 960;
        data->player->pos.y = 980;
    } else
        draw_text("The gate is lock... I have to find a way to enter.", data);
}

void grote(ctr_t *data)
{
    if (data->player->quete_state == 3) {
        data->player->quete_state = 4;
        draw_text("The girl is here. \nI have to bring her back to her father.",
        data);
    }
}
