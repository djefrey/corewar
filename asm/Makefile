##
## EPITECH PROJECT, 2021
## corewar
## File description:
## asm makefile
##

SRC		=	./src/main.c 					\
			./src/splitter.c				\
			./src/compiler.c				\
			./src/write_file.c				\
			./src/file.c					\
			./src/label.c					\
			./src/utils.c					\
			./src/operations/arguments.c	\
			./src/operations/operations.c	\
			./src/operations/op_list.c

LIB_DIR	=	./mylib
INC_DIR	=	./include

CFLAGS	+=	-W -Wall -I$(INC_DIR)

OBJ		=	$(SRC:.c=.o)

NAME	=	asm

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB_DIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIB_DIR) -lmy

debug:	CFLAGS += -g -gdwarf-3
debug:	re

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
