##
## EPITECH PROJECT, 2021
## corewar
## File description:
## corewar makefile
##

MAIN_SRC	=	src/main.c

SRC			=	src/vm.c							\
				src/vm_run.c						\
				src/champion.c						\
				src/process.c						\
				src/cor.c							\
				src/memory.c						\
				src/args.c							\
				src/args_utils.c					\
				src/instructions/instructions.c		\
				src/instructions/arguments.c		\
				src/instructions/read_args.c		\
				src/instructions/operations.c		\
				src/instructions/load.c				\
				src/instructions/st_fork.c			\
				src/instructions/utilitaries.c		\
				src/utils.c

BONUS_SRC	=	../bonus/corewar/src/bonus.c						\
				../bonus/corewar/src/memory.c						\
				../bonus/corewar/src/opengl.c						\
				../bonus/corewar/src/file.c							\
				../bonus/corewar/src/graphics/camera.c				\
				../bonus/corewar/src/graphics/hud.c					\
				../bonus/corewar/src/graphics/scene.c				\
				../bonus/corewar/src/graphics/shader.c				\
				../bonus/corewar/src/graphics/text.c				\
				../bonus/corewar/src/graphics/transform.c			\
				../bonus/corewar/src/graphics/mesh/mesh.c			\
				../bonus/corewar/src/graphics/mesh/cube_mesh.c		\
				../bonus/corewar/src/graphics/gameitems/gameitem.c	\
				../bonus/corewar/src/graphics/gameitems/cube.c		\

TESTS_SRC	=	tests/operations.c					\
				tests/ld.c							\
				tests/st.c							\
				tests/jmp.c							\
				tests/fork.c						\
				tests/utilitaries.c					\
				tests/arguments.c					\
				tests/utils.c

LIB_DIR		=	./mylib
INC_DIR		=	./include

BONUS_INC	=	../bonus/corewar/include

CSFML		=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lGL -lGLU -lGLEW -lm

CFLAGS		+=	-W -Wall -I$(INC_DIR)

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
OBJ			=	$(SRC:.c=.o)
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)
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

debug:	CFLAGS += -g -gdwarf-3
debug:	re

bonus:	CFLAGS += -I$(BONUS_INC) -D BONUS
bonus: fclean $(MAIN_OBJ) $(OBJ) $(BONUS_OBJ)
	make -C $(LIB_DIR)
	gcc $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) $(BONUS_OBJ) -L$(LIB_DIR) -lmy $(CSFML)

clean:
	make -C $(LIB_DIR) clean
	rm -f $(MAIN_OBJ)
	rm -rf $(OBJ)
	rm -rf $(BONUS_OBJ)
	rm -rf $(TESTS_OBJ)
	rm -rf **/*.gcno
	rm -rf **/*.gcda

fclean:	clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re:	fclean all