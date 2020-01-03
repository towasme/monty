#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *op_push - calls different functions
 *@stack: pointer
 *@num: number to manipulate
 *Return: Always
 */

void *op_push(stack_t **stack, unsigned int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		perror("Error: malloc failed");
		exit (EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		*stack = new;
		new->n = num;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		new->n = num;
		(*stack)->prev = new;
		new->next = *stack;
		new->prev = NULL;
		*stack = new;
	}
}
/**¬
  6  *op_pop - calls different functions¬
  7  *@stack: pointer¬
  8  *@num: number to manipulate¬
  9  *Return: Always¬
 10  */

void *op_pop(stack_t **stack, unsigned int num)
{
	stack_t *aux = *stack;
	UNUSED (num);

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pop an empty stack\n")
		exit (EXIT_FAILURE);
	}
	else
	{
		*stack = aux->next;
		(*stack)->prev = NULL;
		free(aux);
	}
}

/**¬
*op_pall - calls different functions¬
*@stack: pointer¬
*@num: number to manipulate¬
*Return: Always¬
*/

void *op_pall(stack_t **stack, unsigned int num)
{
	int counter = 0;
	UNUSED (num);

	while (stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
		counter++;
	}
}

/**¬
*op_pint - calls different functions¬
*@stack: pointer¬
*@num: number to manipulate¬
*Return: Always¬
*/

void *op_pint(stack_t **stack, unsigned int num)
{
	UNUSED (num);

	if (*stack == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
		exit (EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}


/**¬
*op_swap - calls different functions¬
*@stack: pointer¬
*@num: number to manipulate¬
*Return: Always¬
*/

void *op_swap(stack_t **stack, unsigned int num)
{
	UNUSED (num);
	int num_swap = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't swap, stack too short");
		exit (EXIT_FAILURE);
	}
	else
	{
		num_swap = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = num_swap
	}
}

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
