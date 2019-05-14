##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## natahan Makefile
##

NAME = 	lib_nathan.a

SRC	=	load/create_basic_elements.c	\
		load/edit_file.c				\
		load/get_var_name.c				\
		load/get_player.c				\
		load/get_obj.c					\
		load/get_item.c					\
		load/draw_player.c				\
		load/save.c						\
		load/get_inv.c					\
		load/create_ctr.c				\
		load/man_char2.c				\
		load/str_to_word_array.c		\
		load/get_save.c					\
		load/get_map.c					\
		pause/pause_destroy.c			\
		pause/pause_display.c			\
		pause/pause_init.c				\
		pause/pause_loop.c				\
		pause/pause_event.c				\
		load/destroy_basic_elements.c	\
		player_lvl/player_lvl.c			\


OBJ =	$(SRC:.c=.o)

CC =	gcc

RM =	rm -rf

AR =	ar rc

CFLAGS = -W -Wextra -Wall -lm

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
