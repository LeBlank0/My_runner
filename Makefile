##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	get_map.c			\
		background_set.c	\
		player_set.c		\
		map_set.c			\
		parallax.c			\
		player.c			\
		map.c				\
		collision.c			\
		text_set.c			\
		text.c				\
		destroy.c			\
		my_runner.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

LIBFLAGS	=	-L./lib -lmy -l csfml-graphics -l csfml-window \
			-l csfml-audio -l csfml-network -l csfml-system

CFLAGS	=	-g -W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		make -C lib/my/ fclean
		gcc $(OBJ) -o $(NAME) $(LIBFLAGS) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		 clean
		rm -f $(NAME) $(OBJ)
		rm -f libmy.a

re:		fclean all
