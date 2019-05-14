##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of my library
##

NAME =	libmy.a

SRC =	my_getnbr.c		\
	my_revstr.c		\
	my_putnbr_base.c	\
	my_getnbr_base.c	\
	my_nbr_to_str.c		\
	my_nbrlen.c		\
	my_convert_base.c	\
	my_revstr.c		\
	my_strcapitalize.c	\
	my_strcat.c		\
	my_strcmp.c		\
	my_strcpy.c		\
	my_strncpy.c	\
	my_str_isalpha.c	\
	my_str_islower.c	\
	my_str_isnum.c		\
	my_str_isprintable.c	\
	my_str_isupper.c	\
	my_strlowcase.c		\
	my_strncat.c		\
	my_strstr.c		\
	my_strupcase.c		\
	my_strlen.c	\
	man_char2.c	\
	str_to_str_array.c	\
	str_to_word_array.c \
	my_memset.c

OBJ =	$(SRC:.c=.o)

AR =	ar rc

RM =	rm -f

MV = mv

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	$(AR) $(NAME) $(OBJ)
	$(MV) $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../$(NAME)

re:	fclean all
