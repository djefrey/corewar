##
## EPITECH PROJECT, 2021
## corewar
## File description:
## asm makefile
##

SRC		=	./src/main.c \
			./src/my_str_to_word_array.c

INC_DIR	=	./include

CFLAGS	+=	-W -Wall -I$(INC_DIR)

OBJ		=	$(SRC:.c=.o)

NAME	=	asm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L ../corewar/mylib -lmy

debug:	CFLAGS += -g
debug:	re

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all