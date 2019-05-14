##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME = 	lib_tarek.a

SRC	=	movement.c			\
		boss.c				\
		fight.c				\
		hit.c				\
		init_fight.c		\
		player_turn.c		\
		setup_icon.c		\
		init_all.c			\
		move_and_colision.c	\
		fight_event.c		\
		anim_entities.c		\
		utilities.c			\
		set_tab_mstr.c		\
		pnj.c				\
		manage_anim.c	\
		pnj2.c

OBJ =	$(SRC:.c=.o)

CC =	gcc

RM =	rm -rf

AR =	ar rc

CFLAGS = -W -Wextra -Wall -g3

LIBMY = -L../-lmy

CSFMLFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all:
	$(CC) -c $(SRC) $(CSFMLFLAGS) $(CFLAGS)
	$(AR) $(NAME) *.o
	$(RM) *.o

my_test:
	$(CC) src/main.c $(NAME) ../libmy.a $(CSFMLFLAGS) $(CFLAGS) -o test

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
