##
## EPITECH PROJECT, 2020
## evalexper
## File description:
## makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c		\
		lib.c		\
		my_bsq.c	\
		new_tab.c	\
		lib_two.c	\
		exeption.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -I./include -W -Wall -Wextra

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: 	fclean all
