#include "monty.h"
#include <stdio.h>


/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	char *buff_phrase = NULL;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		perror("USAGE: monty file\n");
		EXIT_FAILURE;
	}
	else
	{
		buff_phrase = read_textfile(av[1], &stack);
		printf("%s", buff_phrase);
/*		tokenizar = tokenize(buff_phrase);
	printf("%s\n", tokenizar);*/
	}
	return (0);
}
