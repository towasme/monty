#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**¬
*op_add - calls different functions¬
*@stack: pointer¬
*@num: number to manipulate¬
*Return: Always¬
*/

void op_add(stack_t **stack, unsigned int num)
{
	int sum_num = 0;
	stack_t *aux = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L %d : can't add, stack too short\n", num);
		exit (EXIT_FAILURE);
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
