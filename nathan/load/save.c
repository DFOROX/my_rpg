/*
** EPITECH PROJECT, 2018
** save.c
** File description:
** save
*/

#include "../my.h"

void save_player2(player_t *p, int fd)
{
    my_putstr_fd(fd, " competencies:");
    my_putnbr_fd(fd, p->cpt);
    my_putstr_fd(fd, " competencies_nb:");
    my_putnbr_fd(fd, p->cpt_nb);
    my_putstr_fd(fd, " quete_state:");
    my_putnbr_fd(fd, p->quete_state);
    my_putstr_fd(fd, " hp_max:");
    my_putnbr_fd(fd, p->hp_max);
    my_putstr_fd(fd, " texture:");
    my_putstr_fd(fd, p->path);
    my_putstr_fd(fd, " rect: 0 0 ");
    my_putnbr_fd(fd, p->rect.width);
    my_putstr_fd(fd, " ");
    my_putnbr_fd(fd, p->rect.height);
    my_putstr_fd(fd, "\n");
}

void save_player(player_t *p, int fd)
{
    my_putstr_fd(fd, "player = x:");
    my_putnbr_fd(fd, (int)p->pos.x);
    my_putstr_fd(fd, " y:");
    my_putnbr_fd(fd, (int)p->pos.y);
    my_putstr_fd(fd, " life:");
    my_putnbr_fd(fd, p->life);
    my_putstr_fd(fd, " xp:");
    my_putnbr_fd(fd, p->xp);
    my_putstr_fd(fd, " lvl:");
    my_putnbr_fd(fd, p->lvl);
    my_putstr_fd(fd, " gold:");
    my_putnbr_fd(fd, p->gold);
    my_putstr_fd(fd, " strength:");
    my_putnbr_fd(fd, p->stat[0]);
    my_putstr_fd(fd, " intelligence:");
    my_putnbr_fd(fd, p->stat[1]);
    my_putstr_fd(fd, " speed:");
    my_putnbr_fd(fd, p->speed);
    save_player2(p, fd);
}

void save_ctr(ctr_t *ctr, char *file)
{
    FILE *fc = fopen(file, "w");
    int fd;

    fclose(fc);
    fd = open(file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IWUSR);
    save_player(ctr->player, fd);
    my_putstr_fd(fd, "items =");
    for (int i = 0; i < NB_INV; i++)
    {
        my_putstr_fd(fd, " ");
        my_putnbr_fd(fd, ctr->inv_it[i] ? ctr->inv_it[i]->id : -1);
    }
    write(fd, "\nmap = ", 7);
    my_putnbr_fd(fd, ctr->m);
    write(fd, " ", 1);
    my_putnbr_fd(fd, ctr->maps[ctr->m].pos.x < 0 ? ctr->maps[ctr->m].pos.x : 0);
    write(fd, " ", 1);
    my_putnbr_fd(fd, ctr->maps[ctr->m].pos.y < 0 ? ctr->maps[ctr->m].pos.y : 0);
    write(fd, "\n                                                      \n", 55);
    close(fd);
}
