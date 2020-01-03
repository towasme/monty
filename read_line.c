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
char *read_textfile(char *filename)
{
	ssize_t fd, read_file;
	char *buff;

	if (filename == NULL)
	{
		return (0);
	}
	else
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			return (0);
		}
	}
	buff = malloc(sizeof(char) * 2000);
	if (buff == NULL)
	{
		return (0);
	}
	read_file = read(fd, buff, 2000);
	if (read_file == -1)
	{
		free(buff);
		return (0);
	}
	close(fd);
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
	char **line;

	line = malloc(sizeof(char *) * 2000);
	if (line == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	while (args)
	{
		len = strtok(args, "\n");
		while (len)
		{
			line[pos] = len;
			pos++;
			len = strtok(NULL, " \t\n\r");
		}
		line[pos] = NULL;
		return (line);
	}
}


/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	{
		instruction_t ops[] = {¬
			{"push", op_push},¬
			{"pop", op_pop},¬
			{"pall", op_pall},¬
			{"swap", op_swap},¬
			{"pint", op_pint},¬
			{NULL, NULL}¬
	};
int i = 0;

			while (i <= 4)¬
		{
			if (ops[i].opcode[0] == *s)¬
		{
		return (ops[i].f(stack, );¬
	}
	i++;
	}
	return (NULL);
}
	if (ac != 2)
	{
		perror("USAGE: monty file\n");
		EXIT_FAILURE;
	}
	else
	{
		buff_phrase = read_textfile(av[1]);
		tokenizar = tokenize(buff_phrase);
	printf("%s\n", tokenizar);
	}
	return (0);
}
