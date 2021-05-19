##
## EPITECH PROJECT, 2021
## corewar
## File description:
## asm makefile
##

SRC		=	./src/main.c 					\
			./src/my_str_to_word_array.c	\
			./src/parsing.c					\
			./src/my_asm_to_word_array.c 	\
			./src/core.c					\
			./src/funct_one.c				\
			./src/funct_two.c				\
			./src/funct_three.c				\
			./src/print_file.c				\
			./src/my_strjoin.c				\
			./src/my_strjoin_char.c 		\
			./src/utils.c

LIB_DIR	=	./mylib
INC_DIR	=	./include

CFLAGS	+=	-W -Wall -I$(INC_DIR)

OBJ		=	$(SRC:.c=.o)

NAME	=	asm

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB_DIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIB_DIR) -lmy

debug:	CFLAGS += -g
debug:	re

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all