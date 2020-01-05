#include "monty.h"
#include <stdio.h>

int num_error = 0;
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	stack_t *stack = NULL;

	if (ac != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		read_textfile(av[1], &stack);
/*		printf("%s", buff_phrase);
		tokenizar = tokenize(buff_phrase);
	printf("%s\n", tokenizar);*/
	}
	return (0);
}
