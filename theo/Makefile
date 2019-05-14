##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## lib_theo Makefile
##

NAME =	lib_theo.a

SRC =	menu/menu.c	\
	menu/menu_init.c	\
	menu/menu_init_how_play.c	\
	menu/menu_destroy.c	\
	menu/menu_event.c	\
	menu/menu_mouse_event.c	\
	menu/menu_button.c	\
	sound/manage_vol_sound.c	\
	inventory/inventory.c	\
	inventory/inventory_init.c	\
	inventory/inventory_init_items.c	\
	inventory/inventory_destroy.c	\
	inventory/inventory_event.c	\
	inventory/inventory_mouse_event.c	\
	inventory/inventory_mouse_drag.c	\
	inventory/inventory_display.c	\
	inventory/capital_pts.c	\
	inventory/manage_click.c	\
	trader/trader.c	\
	trader/trader_init_inventory_items.c	\
	trader/trader_init_sell_items.c	\
	trader/trader_init_text.c	\
	trader/trader_event.c	\
	trader/trader_mouse_click.c	\
	trader/trader_mouse_unclick_inv.c	\
	trader/trader_mouse_unclick_inv_to_sell.c	\
	trader/trader_mouse_unclick_sell.c	\
	trader/trader_mouse_drag.c	\
	trader/trader_display.c	\
	trader/trader_set_item_description.c	\
	trader/trader_destroy.c

OBJ =	$(SRC:.c=.o)

RM =	rm -f

AR = ar rc

all:	$(NAME)

$(NAME):
	gcc -W -Wextra -Wall -Werror -c $(SRC)
	$(AR) $(NAME) *.o

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
