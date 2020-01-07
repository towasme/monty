#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *op_add - adds the first two nodes
 *@stack: pointer
 *@num: number to manipulate
 *Return: void
*/

void op_add(stack_t **stack, unsigned int num)
{
	int sum_num = 0;
	stack_t *aux = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	sum_num = (*stack)->n;
	(*stack)->next->n += sum_num;
	*stack = aux->next;
	(*stack)->prev = NULL;
	free(aux);
}

/**
*op_nop - does not do anything
*@stack: pointer
*@num: number to manipulate
*Return: void
*/

void op_nop(stack_t **stack, unsigned int num)
{
	(void) stack;
	(void) num;
}

/**
 *free_grid - frees an array of pointers
 *@grid: array of pointers
 *
 *Return: Always
 */

void free_grid(char **grid)
{
	int i = 0;

	if (!grid)
	{
		return;
	}
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

/**
 * free_stack_list - free list
 * @stack: pointer of a list
 * Return: void
 */

void free_stack_list(stack_t **stack)
{
	stack_t *aux;

	if (*stack == NULL)
	{
		return;
	}
	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		if (aux == NULL)
		{
			return;
		}
		aux->prev = NULL;
		*stack = aux;
	}
	free(*stack);
}


/**
 *ver_str - verifies if the function works
 *@lines: pointer
 *Return: Always
 */
int ver_str(char **lines)
{
	int i = 0;

	while (lines[1][i])
	{
		if ((strcmp(lines[0], "pall") == 0) || (strcmp(lines[0], "pop") == 0) ||
		(strcmp(lines[0], "nop") == 0) || (strcmp(lines[0], "pint") == 0) ||
		(strcmp(lines[0], "swap") == 0) || (strcmp(lines[0], "add") == 0) ||
		(strcmp(lines[0], "sub") == 0))
		{
			return (1);
		}
		if ((lines[1][i] >= 48 && lines[1][i] <= 57) || (lines[1][0] == '-'))
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

