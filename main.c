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
			if (strcmp(ops[i].opcode, *s) == 0)¬
		{
		return (ops[i].f(stack, );¬
	}
	i++;
	}
}

	if (ac != 2)
	{
		perror("USAGE: monty file\n");
		EXIT_FAILURE;
	}
	else
	{
		buff_phrase = read_textfile(av[1]);
		printf("%s", buff_phrase);
/*		tokenizar = tokenize(buff_phrase);
	printf("%s\n", tokenizar);*/
	}
	return (0);
}
