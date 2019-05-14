##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

CC	=	gcc

SRC	=	main.c					\

OBJ		=	$(../SRC:.c=.o)

NAME 	= 	my_rpg

RM		=	rm -rf

CFLAGS = -W -Wextra -Wall -g3

LDFLAGS = -lm

CSFMLFLAGS	=	-lcsfml-graphics \
				-lcsfml-audio	 \
				-lcsfml-window	 \
				-lcsfml-system	 \

LIB = libmy.a
NATHAN = nathan/lib_nathan.a
THEO = theo/lib_theo.a
TAREK = tarek/lib_tarek.a

all:
		make -C tarek/
		make -C nathan/
		make -C theo/
		make -C lib/
		$(CC) $(SRC) $(TAREK) $(THEO) $(NATHAN) $(LIB) $(CFLAGS) $(CSFMLFLAGS) $(LDFLAGS) -o $(NAME)
clean:
		$(RM) $(OBJ)
		$(RM) *.gcno *.gcda *.info *.o

fclean: clean
		$(RM) $(NATHAN) $(THEO) $(TAREK) $(QUENTIN) $(NAME)
		make fclean -C tarek/
		make fclean -C nathan/
		make fclean -C theo/
		make fclean -C lib/

re: fclean all

.PHONY: all clean fclean re
