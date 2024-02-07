##
## EPITECH PROJECT, 2023
## makefile
## File description:
## compile program
##

SRC	=	my_sokoban.c \
		map.c \
		deplacement.c \
		manage_map.c

OBJ_TEST=	$(SRC_TEST:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS += -g

all:	$(NAME)

$(NAME):	$(OBJ)
	cd my_printf/ && make
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L./my_printf/ -lmy -lncurses

clean:
	cd my_printf/ && make clean
	rm *.o

fclean:		clean
	cd my_printf/ && make fclean
	rm -f $(NAME)

re:	fclean all
