/*
** EPITECH PROJECT, 2018
** nathan.h
** File description:
** helps for user
*/

#ifndef _NATHAN_H_
#define _NATHAN_H_

#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <math.h>
#include "include/basic.h"
#include "../my.h"

typedef int bool;

enum {false, true};

/*  Create:     */
sfRenderWindow *create_window(char *name, char *fd);
obj_t create_obj(char *fd, sfVector2f pos, sfIntRect rect, int id);
void create_ctr(ctr_t *ctr);
void load_ctr(ctr_t *ctr, char *path);

void draw_player(player_t *p, sfRenderWindow *window);
void destroy_player(player_t *player);

bool is_var_name(char *str, char *name, char p);
bool is_item_name(char *str, char *name);

/*  Get save:   */
void get_player(ctr_t *ctr, char **file);
void get_obj(ctr_t *ctr);
void get_item(char *fd, ctr_t *ctr);
void get_inv(char **file, ctr_t *ctr);
void get_map(ctr_t *ctr);

/*  Read save:  */
char *read_file(char *file);
char **get_save(char *path);

/*  Save:       */
void my_putnbr_fd(int fd, int nb);
void my_putstr_fd(int fd, char *str);
void save_ctr(ctr_t *ctr, char *path);

char *my_strcpyn(char *str);

#endif /* !_NATHAN_H_ */
