#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *read_textfile - program that reads a file
 *@filename: The character to print
 *Return: bytes read
 */
void read_textfile(char *filename, stack_t **stack)
{
	FILE *fd;
	size_t size = 0;
	char *buff = NULL;
	int contador = 0;

	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit (EXIT_FAILURE);
	}
	buff = malloc(sizeof(char) * 2000);
	if (buff == NULL)
	{
		perror("Error: malloc failed");
		exit (EXIT_FAILURE);
	}
	while (getline(&buff, &size, fd) != EOF)
	{
		contador++;
		compare_string(buff, stack, contador);
	}
	fclose(fd);
	free(buff);
}

/**
 * tokenize - splits a string into different argumnets
 * @args: string with the arguments to be tokenize
 *
 * Return: double pointer of the arrays of strings
 */

char **tokenize(char *args)
{
	int pos = 0;
	char *len;
	char **lines;

	lines = malloc(sizeof(char *) * 64);
	if (lines == NULL)
	{
		perror("Error: malloc failed");
		exit (EXIT_FAILURE);
	}

	len = strtok(args, " \n");
	if (len == NULL)
	{
		return (NULL);
	}
	while (len)
	{
		printf("%d %s\n", pos, len);
		lines[pos] = len;
		len = strtok(NULL, " \n");
		pos++;
	}
/*	lines[pos] = NULL;*/
	return (lines);
}


/**
 * compare_string - splits a string into different argumnets
 * @buff: string with the arguments to be tokenize
 *
 * Return: double pointer of the arrays of strings
 */
void compare_string(char *buff, stack_t **stack, int contador)
{
	char **lines = NULL;
	int i = 0;

		instruction_t ops[] = {
			{"push", op_push},
			{"pall", op_pall},
/*			{"pop", op_pop},
			{"swap", op_swap},
			{"pint", op_pint},
			("nop", op_nop},*/
			{NULL, NULL}
	};

	lines = tokenize(buff);
/*	printf("%s\n", lines[0]);*/
	num_error = atoi(lines[1]);
/*	printf("%d\n", num_error);*/

	while (ops[i].opcode)
	{
		if (strcmp(lines[0], ops[i].opcode) == 0)
		{
			ops[i].f(stack, contador);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", contador, lines[0]);
	free(lines);
	exit(EXIT_FAILURE);
}





