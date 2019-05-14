/*
** EPITECH PROJECT, 2019
** trader.h
** File description:
** header of trader
*/

#ifndef trader
#define trader

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

#define INV_HITBOX_X_MIN 407 + POS_INVENTORY_X
#define INV_HITBOX_Y_MIN 164 + POS_INVENTORY_Y
#define INV_HITBOX_X_MAX 610 + POS_INVENTORY_X
#define INV_HITBOX_Y_MAX 520 + POS_INVENTORY_Y

#endif

#ifndef TRADER_HITBOX
#define TRADER_HITBOX

#define WEAPON_1_X 676
#define WEAPON_1_Y 397
#define WEAPON_1_LIM_X 740
#define WEAPON_1_LIM_Y 461

#define STAFF_1_X 748
#define STAFF_1_Y 397
#define STAFF_1_LIM_X 812
#define STAFF_1_LIM_Y 461

#define HELMET_1_X 820
#define HELMET_1_Y 397
#define HELMET_1_LIM_X 884
#define HELMET_1_LIM_Y 461

#define ARMOR_1_X 892
#define ARMOR_1_Y 397
#define ARMOR_1_LIM_X 956
#define ARMOR_1_LIM_Y 461

#define WEAPON_2_X 676
#define WEAPON_2_Y 469
#define WEAPON_2_LIM_X 740
#define WEAPON_2_LIM_Y 533

#define STAFF_2_X 748
#define STAFF_2_Y 469
#define STAFF_2_LIM_X 812
#define STAFF_2_LIM_Y 533

#define HELMET_2_X 820
#define HELMET_2_Y 469
#define HELMET_2_LIM_X 884
#define HELMET_2_LIM_Y 533

#define ARMOR_2_X 892
#define ARMOR_2_Y 469
#define ARMOR_2_LIM_X 956
#define ARMOR_2_LIM_Y 533

#define WEAPON_3_X 676
#define WEAPON_3_Y 541
#define WEAPON_3_LIM_X 740
#define WEAPON_3_LIM_Y 605

#define STAFF_3_X 748
#define STAFF_3_Y 541
#define STAFF_3_LIM_X 812
#define STAFF_3_LIM_Y 605

#define HELMET_3_X 820
#define HELMET_3_Y 541
#define HELMET_3_LIM_X 884
#define HELMET_3_LIM_Y 605

#define ARMOR_3_X 892
#define ARMOR_3_Y 541
#define ARMOR_3_LIM_X 956
#define ARMOR_3_LIM_Y 605

#define WEAPON_4_X 676
#define WEAPON_4_Y 613
#define WEAPON_4_LIM_X 740
#define WEAPON_4_LIM_Y 677

#define STAFF_4_X 748
#define STAFF_4_Y 613
#define STAFF_4_LIM_X 812
#define STAFF_4_LIM_Y 677

#define HELMET_4_X 820
#define HELMET_4_Y 613
#define HELMET_4_LIM_X 884
#define HELMET_4_LIM_Y 677

#define ARMOR_4_X 892
#define ARMOR_4_Y 613
#define ARMOR_4_LIM_X 956
#define ARMOR_4_LIM_Y 677

#define SELL_HITBOX_X_MIN 676
#define SELL_HITBOX_Y_MIN 397
#define SELL_HITBOX_X_MAX 956
#define SELL_HITBOX_Y_MAX 677

#endif

#ifndef TRADER_MESSAGE_
#define TRADER_MESSAGE_

#define NB_TRADER_MESSAGE 4
#define TRADER_MESSAGE_FIX 2
#define COST_MSG_POS 2
#define GOLD_MSG_POS 3
#define TRADER_MESSAGE_X_MIN 622 + 64
#define TRADER_MESSAGE_Y_MIN 720
#define TRADER_MESSAGE_SIZE 22

#endif

typedef struct trader_message_s
{
    char str[256];
    sfText *txt;
    sfVector2f pos;
} trader_message_t;

typedef struct trader_s
{
    item_t inv_it[NB_INV];
    item_t sel_it[NB_ITEM];
    item_t *inv_drag_item;
    item_t sell_drag_item;
    sfVector2f item_pos[NB_INV];
    sfVector2f item_lim_pos[NB_INV];
    sfVector2f sell_pos[NB_ITEM];
    sfVector2f sell_lim_pos[NB_ITEM];
    trader_message_t trader_msg[NB_TRADER_MESSAGE];
    sfText *warning_txt;
    sfText *item_lore_txt;
    int drag_inv;
    int drag_sell;
    int is_empty;
    sfVector2i m_pos;
    sfVector2f m_pos_f;
    char item_lore_str[512];
} trader_t;

void trader_init(ctr_t *, trader_t *);
void trader_set_inventory_items_pos(trader_t *);
void trader_sell_init_items(ctr_t *, trader_t *);
void trader_fill_sell_items_pos(trader_t *);
void trader_set_sell_items_pos(trader_t *);
void trader_destroy(trader_t *);
void trader_init_warning_message(ctr_t *, trader_t *);
void trader_init_lore_message(ctr_t *, trader_t *);
void trader_init_trader_message(ctr_t *, trader_t *);
void trader_event(ctr_t *, int *, trader_t *);
void trader_mouse_click(ctr_t *, trader_t *);
void trader_mouse_unclick_inv(ctr_t *ctr, trader_t *);
void trader_mouse_unclick_sell(ctr_t *ctr, trader_t *);
void trader_mouse_unclick_inv_to_inv(ctr_t *ctr, trader_t *);
void trader_mouse_unclick_inv_to_sell(ctr_t *ctr, trader_t *);
void trader_mouse_unclick_sell(ctr_t *, trader_t *);
void trader_mouse_drag(trader_t *);
void draw_trader(ctr_t *, trader_t *);
void trader_set_item_description(ctr_t *, trader_t *);

#endif
