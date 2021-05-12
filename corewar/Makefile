##
## EPITECH PROJECT, 2021
## corewar
## File description:
## corewar makefile
##

MAIN_SRC	=	src/main.c

SRC			=	src/vm.c							\
				src/champion.c						\
				src/process.c						\
				src/cor.c							\
				src/instructions/arguments.c		\
				src/instructions/operations.c		\
				src/utils.c

TESTS_SRC	=	tests/operations.c					\
				tests/utils.c

LIB_DIR		=	./mylib
INC_DIR		=	./include

CFLAGS		+=	-W -Wall -I$(INC_DIR)

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
OBJ			=	$(SRC:.c=.o)
TESTS_OBJ	=	$(TESTS_SRC:.c=.o)

NAME		=	corewar
NAME_TESTS	=	corewar_tests

all:	$(NAME)

$(NAME):	$(MAIN_OBJ)	$(OBJ)
	make -C $(LIB_DIR)
	gcc $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) -L$(LIB_DIR) -lmy

tests_run: CFLAGS += --coverage
tests_run:	fclean $(TESTS_OBJ)	$(OBJ)
	make -C $(LIB_DIR)
	gcc $(CFLAGS) -o $(NAME_TESTS) $(OBJ) $(TESTS_OBJ) -L$(LIB_DIR) -lmy -lcriterion
	./$(NAME_TESTS)

debug:	CFLAGS += -g
debug:	re

clean:
	make -C $(LIB_DIR) clean
	rm -f $(MAIN_OBJ)
	rm -rf $(OBJ)
	rm -rf $(TESTS_OBJ)
	rm -rf $(wildcard **/*.gcno)
	rm -rf $(wildcard **/*.gcda)

fclean:	clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re:	fclean all