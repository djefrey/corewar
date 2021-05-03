##
## EPITECH PROJECT, 2021
## corewar
## File description:
## asm makefile
##

SRC		=	./src/main.c

INC_DIR	=	./include

CFLAGS	+=	-W -Wall -I$(INC_DIR)

OBJ		=	$(SRC:.c=.o)

NAME	=	asm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

debug:	CFLAGS += -g
debug:	re

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all