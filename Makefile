##
## EPITECH PROJECT, 2023
## makefile
## File description:
## compile program
##

SRC	=	my_sokoban.c \
		map.c \
		deplacement.c

OBJ_TEST=	$(SRC_TEST:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS += -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all
