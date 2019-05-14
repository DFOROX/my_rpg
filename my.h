/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib
*/

#ifndef MY_H_
#define MY_H_

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include "struct.h"
#include "lib.h"

void save_ctr(ctr_t *ctr, char *path);
void create_ctr(ctr_t *ctr);
void load_ctr(ctr_t *ctr, char *path);
char **get_save(char *path);
int check_colision(sfVector2f pos, map_t map);
void set_volume_off(ctr_t *);
void set_volume_on(ctr_t *);
void set_volume(ctr_t *, float);
void movement_fight(ctr_t *);
void main_menu(ctr_t *);
void main_inventory(ctr_t *, int *);
void main_trader(ctr_t *);
void loop_pause(ctr_t *ctr);
void update_level(ctr_t *ctr);
void destroy_game(ctr_t *ctr);
void look_colision(map_t map, ctr_t *ctr);

#endif
