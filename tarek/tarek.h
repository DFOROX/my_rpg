/*
** EPITECH PROJECT, 2019
** tarek.h
** File description:
** tarek.h
*/

#ifndef tarek
#define tarek
#define KEY sfKeyboard_isKeyPressed
#include "../my.h"

void init_rect(ctr_t *ctr);
void init_rect2(ctr_t *ctr);
void loop_anim_monster(ctr_t *ctr, int max, int index);
void loop_anim_competencies(ctr_t *ctr, int index, int a, int max);
void set_pos_light(ctr_t *data, monster_t *m);
monster_t *create_boss(void);
void boss(ctr_t *data);
void poll_event_manager(ctr_t *ctr, int *inventory_state);
void anim_fight(ctr_t *data, monster_t *m, int timer);
char *my_itoa(int nb);
monster_t *heal(monster_t *monsters);
void fight_loop(monster_t *m, ctr_t *d);
void fight(ctr_t *data);
void display_anim(ctr_t *data, monster_t *monsters, int a, int b);
monster_t *hit_zone(int p[2], ctr_t *d, monster_t *m);
void get_bonus(int p[2], ctr_t *data, monster_t *m);
monster_t *hard_hit(int p[2], ctr_t *data, monster_t *m, int i);
void dgt(ctr_t *data, monster_t m);
void init_asset(ctr_t *ctr);
void draw_all(ctr_t *ctr);
void state_anim(ctr_t *ctr, int *n);
void movement_fight(ctr_t *ctr);
char *stupid(char *str);
monster_t init_monster4(int val);
monster_t init_monster3(int val);
monster_t init_monster1(int val);
monster_t *create_monsters(ctr_t *data);
void manage_anim_mstr(ctr_t *data);
void draw_anim(ctr_t *data, monster_t *monsters, int a, int b);
rect_t set_rect_player(ctr_t *ctr, int x, int y, map_t map);
int move_player_up(ctr_t *ctr);
int move_player_down(ctr_t *ctr);
int move_player_right(ctr_t *ctr);
int move_player_left(ctr_t *ctr);
void change_map3(ctr_t *ctr);
void change_map2(ctr_t *ctr);
void change_map(ctr_t *ctr);
void loop_anim_player(ctr_t *play);
void spawn_fight(ctr_t *var);
int key(int k);
void display(ctr_t *data, monster_t *monsters);
monster_t *hit(int p[2], ctr_t *d, monster_t *m, int i);
monster_t *choose_cible(int p[2], ctr_t *data, monster_t *monsters, int i);
monster_t *p_turn(ctr_t *d, monster_t *m);
void draw_text(char *str, ctr_t *data);
void farmer(ctr_t *data);
void guard(ctr_t *data);
void gate(ctr_t *data);
void grote(ctr_t *data);
void inn(ctr_t *data);
void set_pos_tab4(monster_t *monsters, ctr_t *data, int index, int index2);
void set_pos_tab1(monster_t *monsters, ctr_t *data, int index, int index2);
void set_pos_tab3(monster_t *monsters, ctr_t *data, int index, int index2);
void set_monster_state(ctr_t *data, monster_t *monsters);
void init_pos_icone(ctr_t *data);
void select_comp(ctr_t *data, int p[2], monster_t *monsters);
void init_rect3(ctr_t *ctr);
void init_rect4(ctr_t *ctr);
void set_pos_buff(ctr_t *data);
void set_pos_compt(ctr_t *data, int j);
void init_vect_mstr(monster_t *monsters);
void print_spt(ctr_t *data, monster_t *monsters);
void choose_cible2(ctr_t *data, monster_t *monsters, int i);

#endif
