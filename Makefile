##
## EPITECH PROJECT, 2023
## CSFML_WORKSHOP
## File description:
## Makefile
##

CC      =		gcc

SRC     =		main.c \
				src/create_sprites.c \
				src/create_text.c \
				src/init_struct.c \
				src/display.c \
				src/analyse_event.c \
				src/menu.c \
				src/settings.c \
				src/tools.c \
				src/read_map.c \
				src/free_funcs.c	\
				src/game.c	\
				src/animation.c	\

OBJ     =       $(SRC:.c=.o)


CFLAGS  =       -Wextra -g3 -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm

CPPFLAGS	=	-I./includes

NAME    =		game

all:    $(NAME)

$(NAME):        $(OBJ)
		$(CC) -g3 -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)
		make clean

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY: all clean fclean re