##
## EPITECH PROJECT, 2021
## corewar
## File description:
## corewar makefile
##

SRC		=	src/main.c				\
			src/vm.c				\
			src/champion.c			\
			src/process.c			\
			src/cor.c				\
			src/utils.c

LIB_DIR	=	./mylib
INC_DIR	=	./include

CFLAGS	+=	-W -Wall -I$(INC_DIR)

OBJ		=	$(SRC:.c=.o)

NAME	=	corewar

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB_DIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIB_DIR) -lmy

debug:	CFLAGS += -g
debug:	re

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ)

fclean:	clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re:	fclean all