#include "monty.h"
#include <stdio.h>


/**
 * main - check the code for Holberton School students.
 *@ac: number of arguments passed
 *@av: arguments
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
	}
	return (0);
}
