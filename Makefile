#
# Makefile for monty.c
#

monty: aux_func.c func_lib.c read_line.c main.c more_func_lib.c
	gcc -Wall -Werror -Wextra -pedantic aux_func.c func_lib.c read_line.c more_func_lib.c main.c -o monty
leaks: aux_func.c func_lib.c read_line.c main.c more_func_lib.c
	gcc -g -Wall -Werror -Wextra -pedantic aux_func.c func_lib.c read_line.c more_func_lib.c main.c -o monty && valgrind --leak-check=full --show-leak-kinds=all ./monty 00.m
debug: aux_func.c func_lib.c read_line.c main.c more_func_lib.c
	gcc -ggdb -Wall -Werror -Wextra -pedantic aux_func.c func_lib.c read_line.c more_func_lib.c main.c -o monty
clean:
	rm -f monty
