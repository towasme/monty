#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**¬
*op_add - calls different functions¬
*@stack: pointer¬
*@num: number to manipulate¬
*Return: Always¬
*/

void *op_add(stack_t **stack, unsigned int num)
{
	UNUSED (num);
	int sum_num = 0;
	stack_t *aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't add, stack too short");
		exit (EXIT_FAILURE);
	}
	else
	{
	sum_num = (*stack)->n;
	(*stack)->next->n += sum_num;
	*stack = aux->next;¬
	(*stack)->prev = NULL;¬
	free(aux);
	}
}
