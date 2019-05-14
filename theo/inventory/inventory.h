/*
** EPITECH PROJECT, 2019
** inventory.h
** File description:
** inventory header
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#ifndef MY_H_
#include "../../my.h"
#endif

#ifndef INVENTORY_HITBOX
#define INVENTORY_HITBOX

#define HELMET_POS_X 1124
#define HELMET_POS_Y 405
#define HELMET_LIM_X 1188
#define HELMET_LIM_Y 469
#define ARMOR_POS_X 1124
#define ARMOR_POS_Y 501
#define ARMOR_LIM_X 1188
#define ARMOR_LIM_Y 564
#define WEAPON_POS_X 1037
#define WEAPON_POS_Y 501
#define WEAPON_LIM_X 1101
#define WEAPON_LIM_Y 565
#define CASE_1_X 1088
#define CASE_1_Y 610
#define CASE_1_LIM_X 1152
#define CASE_1_LIM_Y 674
#define CASE_2_X 1088
#define CASE_2_Y 682
#define CASE_2_LIM_X 1152
#define CASE_2_LIM_Y 746
#define CASE_3_X 1160
#define CASE_3_Y 610
#define CASE_3_LIM_X 1224
#define CASE_3_LIM_Y 674
#define CASE_4_X 1160
#define CASE_4_Y 681
#define CASE_4_LIM_X 1224
#define CASE_4_LIM_Y 745

#define POS_INVENTORY_X 622
#define POS_INVENTORY_Y 233
#define INVENTORY_WIDTH 675
#define INVENTORY_HEIGHT 614

#define INV_HITBOX_X_MIN 407
#define INV_HITBOX_Y_MIN 164
#define INV_HITBOX_X_MAX 610
#define INV_HITBOX_Y_MAX 520

#endif

#define TEXT_NB 19
#define STAT_FIX 9
#define STAT_X_MIN 622 + 64
#define STAT_Y_MIN 164 + 233

typedef struct stat_inventory_s
{
    char str[16];
    sfText *txt;
    int s_txt;
    sfColor color[3];
    sfVector2i pos1;
    sfVector2i pos2;
    sfVector2f pos3;
    int state;
} stat_inventory_t;

typedef struct inventory_s
{
    stat_inventory_t *sta;
    int drag_item;
    item_t *item;
    item_t inv_it[NB_INV];
    sfVector2f item_pos[NB_INV];
    sfVector2f item_lim_po[NB_INV];
    int type[NB_INV];
    sfVector2i mouse_pos;
    sfVector2f mouse_pos_f;
    sfText *warning_txt;
    int is_empty;
    sfText *item_lore_txt;
    char str_item_lore[256];
} inventory_t;

void init_inventory(ctr_t *, stat_inventory_t **, inventory_t *);
void inventory_sprite(ctr_t *);
void inventory_init_items(ctr_t *, inventory_t *);
void static_item_pos(inventory_t *);
void inventory_init_items(ctr_t *, inventory_t *);
void inventory_init_items_pos(inventory_t *);
void inventory_event(ctr_t *, int *, inventory_t *);
void inventory_mouse_click(inventory_t *);
void inventory_mouse_unclick(ctr_t *, inventory_t *);
void inventory_mouse_drag(ctr_t *, inventory_t *);
void draw_inventory(ctr_t *, stat_inventory_t **, inventory_t *);
void inventory_destroy(stat_inventory_t **, inventory_t *);
void set_pos_button(ctr_t *, stat_inventory_t **);
void set_pos_click(ctr_t *, stat_inventory_t **);
void pos_click1(ctr_t *ctr, stat_inventory_t **stats);
void pos_click2(ctr_t *ctr, stat_inventory_t **stats);
void pos_click3(ctr_t *ctr, stat_inventory_t **stats);
void pos_click4(ctr_t *ctr, stat_inventory_t **stats);

#endif
