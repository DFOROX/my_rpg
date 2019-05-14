/*
** EPITECH PROJECT, 2018
** get_obj.c
** File description:
** get_obj
*/

#include "../my.h"

void load_obj(char *path, ctr_t *ctr, int id)
{
    struct dirent *file;
    DIR *fd = opendir(path);

    while (fd && (file = readdir(fd)))
        if (file->d_name[0] != '.') {
            ctr->obj[my_getnbr(file->d_name)] = create_obj(my_strcatn(path, \
            file->d_name), (sfVector2f) {0, 0}, (sfIntRect) \
            {0, 0, 0, 0}, id);
        }
    if (fd)
        closedir(fd);
}

void get_obj(ctr_t *ctr)
{
    load_obj(PATH_IMG, ctr, 1);
    load_obj(PATH_MUSIC, ctr, 2);
    load_obj(PATH_FONT, ctr, 3);
}
