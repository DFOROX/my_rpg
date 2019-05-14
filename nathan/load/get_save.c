/*
** EPITECH PROJECT, 2018
** get_obj.c
** File description:
** get_obj
*/

#include "../my.h"

int get_nb_save(char *path)
{
    struct dirent *file;
    DIR *fd = opendir(path);
    int n = 0;

    while (fd && (file = readdir(fd)))
        n += (file->d_name[0] != '.') ? 1 : 0;
    if (fd)
        closedir(fd);
    return (n);
}

char **get_save(char *path)
{
    struct dirent *file;
    DIR *fd = opendir(path);
    char **save;
    int n = 0;

    save = malloc(sizeof(char *) * (get_nb_save(path) + 1));
    while (fd && (file = readdir(fd)))
        if (file->d_name[0] != '.') {
            save[n] = my_strcpyn(file->d_name);
            n++;
        }
    if (fd)
        closedir(fd);
    save[n] = NULL;
    return (save);
}
