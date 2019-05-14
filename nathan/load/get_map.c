/*
** EPITECH PROJECT, 2018
** get_obj.c
** File description:
** get_obj
*/

#include "../my.h"

int check_colision(sfVector2f pos, map_t map)
{
    if (pos.x <= 0 || pos.y <= 0 || pos.x / 64 >= map.size.x || \
    pos.y / 64 >= map.size.y)
        return (0);
    return (map.map[(int)pos.y / 64][(int)pos.x / 64]);
}

void create_parce_map(map_t *map, char *file)
{
    char **tmp = my_str_to_word_array(file, "\n");
    int n = 0;
    int m = my_strlen(*tmp);

    for (; tmp[n]; n++);
    map->map = malloc(sizeof(char *) * (n + 1));
    map->map[n] = NULL;
    for (int i = 0; i < n; i++) {
        map->map[i] = malloc(m + 1);
        for (int j = 0; j < m; j++)
            map->map[i][j] = tmp[i][j] - 48;
    }
    map->size.y = n;
    map->size.x = m;
}

void create_map(ctr_t *ctr, char *name, int n)
{
    if (n > NB_MAP) {
        ctr->maps[n / 10].pos2 = (sfVector2f) {0, 0};
        ctr->maps[n / 10].text2 = \
        sfTexture_createFromFile(my_strcatn(PATH_MAP, name), NULL);
        ctr->maps[n / 10].spt2 = sfSprite_create();
        sfSprite_setTexture(ctr->maps[n / 10].spt2, \
        ctr->maps[n / 10].text2, sfTrue);
        sfSprite_setPosition(ctr->maps[n / 10].spt2, ctr->maps[n / 10].pos2);
    } else {
        ctr->maps[n].pos = (sfVector2f) {0, 0};
        ctr->maps[n].text = \
        sfTexture_createFromFile(my_strcatn(PATH_MAP, name), NULL);
        ctr->maps[n].spt = sfSprite_create();
        sfSprite_setTexture(ctr->maps[n].spt, ctr->maps[n].text, sfTrue);
        sfSprite_setPosition(ctr->maps[n].spt, ctr->maps[n].pos);
    }
}

void get_map(ctr_t *ctr)
{
    struct dirent *file;
    DIR *fd = opendir(PATH_MAP);
    int n = 0;

    for (int i = 0; i < NB_MAP; i++)
        ctr->maps[i] = (map_t) {0};
    while (fd && (file = readdir(fd))) {
        n = my_strlen(file->d_name);
        if (file->d_name[0] != '.' && n >= 5 && file->d_name[n - 1] == 'g' && \
        file->d_name[n - 2] == 'n' && file->d_name[n - 3] == 'p' && \
        file->d_name[n - 4] == '.')
            create_map(ctr, file->d_name, my_getnbr(file->d_name));
        else if (file->d_name[0] != '.')
            create_parce_map(&ctr->maps[my_getnbr(file->d_name)], \
            read_file(my_strcatn(PATH_MAP, file->d_name)));
    }
    if (fd)
        closedir(fd);
}
