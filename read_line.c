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
 *@stack: stack to work with
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
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &size, fd) != EOF)
	{
		if (strcmp(buff, "\n") != 0)
		{
		/*comprobar si lo primero que llega de getline en el primer earray es valido, entonces que si entre,se haec por medio de una funcion que compare*/
			contador++;
			compare_string(buff, stack, contador);
		}
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
	char *len = NULL;
	char **lines = NULL;

	lines = malloc(sizeof(char *) * 64);
	if (lines == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	len = strtok(args, " \n\t");
/*	printf("%slen si es nullo", len);*/
	if (len == NULL)
	{
/*		printf("%slines si es nullo", lines[0]);*/
		free(len);
		return (NULL);
	}
	while (len)
	{
/*		printf("tokens de la linea [%d] token correspondiente:%s\n", pos, len);*/
		lines[pos] = len;
		len = strtok(NULL, " \n");
		pos++;
	}
	free(len);
	return (lines);
}


/**
 * compare_string - splits a string into different argumnets
 * @buff: string with the arguments to be tokenize
 * @stack: stack to work with
 * @contador: counter to store the line number
 * Return: double pointer of the arrays of strings
 */
void compare_string(char *buff, stack_t **stack, int contador)
{char **lines = NULL;
	int i = 0, cont_no_match = 0;

		instruction_t ops[] = {
			{"push", op_push},
			{"pall", op_pall},
			{"pop", op_pop},
			{"swap", op_swap},
			{"pint", op_pint},
			{"nop", op_nop},
			{"add", op_add},
			{"sub", op_sub},
			{NULL, NULL}
	};
	lines = tokenize(buff);
	while (ops[i].opcode != NULL && lines[0] != NULL && ver_str(lines) == 1)
	{
		if (strcmp(ops[i].opcode, lines[0]) == 0)
		{
			if (strcmp("pall", lines[0]) == 0)
			{ops[1].f(stack, contador); }
			else
			{num_error = atoi(lines[1]);
				ops[i].f(stack, contador);
				break; } }
		else
		{cont_no_match++; }
	i++;
	}
	if (cont_no_match == 8)
	{fprintf(stderr, "L%d: unknown instruction %s\n", contador, lines[0]);
		free_grid(lines);
		exit(EXIT_FAILURE); }
	if ((strcmp("push", lines[0]) == 0) && (ver_str(lines) == 0))
	{fprintf(stderr, "L%d: usage: push integer\n", contador);
/*		free_grid(lines);*/
		exit(EXIT_FAILURE); }
/*	free_grid(lines);*/
	free(lines);
}

