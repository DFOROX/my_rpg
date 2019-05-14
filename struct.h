/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "my.h"
#include "lib.h"

#define SIZE_X  1920
#define SIZE_Y  1080

#define NB_OBJ 51
#define NB_MAP 8
#define NB_ITEM 16
#define NB_INV 7
#define PATH_SAVE "assets/save/"
#define PATH_DEFAULT "assets/default"
#define PATH_ITEM "assets/items"
#define PATH_IMG "assets/img/"
#define PATH_MUSIC "assets/music/"
#define PATH_FONT "assets/font/"
#define PATH_MAP "assets/map/"

typedef struct rect_s
{
    sfVector2f a;
    sfVector2f b;
    sfVector2f c;
    sfVector2f d;
} rect_t;

typedef struct item_s
{
    sfTexture *text;
    sfSprite *spt;
    sfVector2f pos;
    sfIntRect rect;
    char *name;
    char *lore;
    char *path;
    int id;
    int stat[2];
    int type;
    int price;
} item_t;

typedef struct player_s
{
    sfTexture *text;
    sfSprite *spt;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    char *path;
    float seconds;
    int life;
    int stat[2];
    int speed;
    int xp;
    int gold;
    int cpt_nb;
    int cpt;
    int quete_state;
    int boost;
    int hp_max;
    int lvl;
    sfVector2f pos_map;
} player_t;

typedef struct map_s
{
    sfTexture *text;
    sfTexture *text2;
    sfSprite *spt;
    sfSprite *spt2;
    sfVector2f pos;
    sfVector2f pos2;
    sfVector2f size;
    char **map;
} map_t;

typedef struct monster_s
{
    int pv;
    int res[2];
    int type;
    char *name;
    int dgt_max;
    int dgt_min;
    sfVector2f mstr1;
    sfVector2f mstr2;
    sfVector2f mstr3;
    int xp;
    int loot;
    sfSprite *sprite;
    int speed;
} monster_t;

typedef struct obj_s {
    sfTexture *texture;
    sfSprite *spt;
    sfIntRect rect;
    sfVector2f v2f;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f pos_icon[7];
    sfFont *font;
    sfText *txt;
    sfMusic *music;
    sfClock *clk;
    int id;
} obj_t;

typedef struct ctr_s
{
    obj_t obj[NB_OBJ];
    player_t *player;
    monster_t (*init_monster[4])(int);
    void (*pnj[7])(struct ctr_s*);
    item_t items[NB_ITEM];
    item_t *inv_it[NB_INV];
    map_t maps[NB_MAP];
    monster_t mst[7];
    int state;
    int game_state;
    int save_exist;
    int m;
    sfRenderWindow *window;
    sfEvent event;
} ctr_t;

#endif
