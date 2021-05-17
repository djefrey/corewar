##
## EPITECH PROJECT, 2021
## corewar
## File description:
## main makefile
##

ASM		=	./asm
COREWAR	=	./corewar

all:
	make -C $(ASM)
	make -C $(COREWAR)

tests_run:
	make -C $(COREWAR) tests_run

clean:
	make -C $(ASM) clean
	make -C $(COREWAR) clean

fclean:
	make -C $(ASM) fclean
	make -C $(COREWAR) fclean

re:
	make -C $(ASM) re
	make -C $(COREWAR) re