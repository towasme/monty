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
char *read_textfile(char *filename, stack_t **stack)
{
	FILE *fd;
	size_t size = 0;
	char *buff = malloc(sizeof(char) * 2000);
	int contador = 0;

	if (filename == NULL)
	{
		perror("USAGE: monty file");
		exit (EXIT_FAILURE);
	}
	else
	{
		fd = fopen(filename, O_RDONLY);
		if (fd == -1)
		{
			fprintf(stderr, "Error: Can't open file %s\n", filename);
			exit (EXIT_FAILURE);
		}
	}
	if (buff == NULL)
	{
		perror("Error: malloc failed");
		exit (EXIT_FAILURE);
	}
	while (getline(&buff, &size, fd) != EOF)
	{
		contador++;
		compare_string(buff, contador, stack);
	}
/*
	read_file = fread(fd, buff, 2000);
	if (read_file == -1)
	{
		free(buff);
		return (0);
	}
*/
	fclose(fd);
	return (buff);
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
		exit(EXIT_FAILURE);
	}

	len = strtok(args, " \n");
		while (len)
		{
			lines[pos] = len;
			len = strtok(NULL, " \n");
			pos++;
		}
		lines[pos] = NULL;
		return (lines);
	}
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
	int i;

		instruction_t ops[] = {¬
			{"push", op_push},¬
			{"pop", op_pop},¬
			{"pall", op_pall},¬
			{"swap", op_swap},¬
			{"pint", op_pint},¬
			{NULL, NULL}¬
	};

	lines = tokenize(buff);
	num_error = atoi(lines[1]);

	if (lines[0] == NULL)
	{
	}
	for (i = 0; i < 6; i++)
	{
		if (strcmp(lines[0], ops[i].opcode) == 0)
		{
			ops[i].f(stack, contador);
		}
	}
}





