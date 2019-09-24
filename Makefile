##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC	=	src/main.c	\
		src/create_obj.c	\
		src/interaction.c	\
		src/move.c	\
		src/tab.c	\
		src/score.c	\
		src/error.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include/

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	 gcc -o $(NAME) $(CFLAGS) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfm\
l-audio -lcsfml-system

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f *~
	rm -f libmy.a

re:	fclean all
