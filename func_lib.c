#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *op_push - calls different functions
 *@stack: pointer
 *@line number: number to manipulate
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
  6  *op_push - calls different functions¬
  7  *@stack: pointer¬
  8  *@line number: number to manipulate¬
  9  *Return: Always¬
 10  */

void *op_pop(stack_t **stack, unsigned int num)
{
}

/**¬
  6  *op_push - calls different functions¬
  7  *@stack: pointer¬
  8  *@line number: number to manipulate¬
  9  *Return: Always¬
 10  */
void *op_pall(stack_t **stack, unsigned int num)
{
}

/**¬
*op_push - calls different functions¬
*@stack: pointer¬
*@line number: number to manipulate¬
*Return: Always¬
*/

void *op_pint(stack_t **stack, unsigned int num)
{
}

/**¬
*op_push - calls different functions¬
*@stack: pointer¬
*@line number: number to manipulate¬
*Return: Always¬
*/

void *op_swap(stack_t **stack, unsigned int num)
{
}

/**¬
  6  *op_push - calls different functions¬
  7  *@stack: pointer¬
  8  *@line number: number to manipulate¬
  9  *Return: Always¬
 10  */

void *op_add(stack_t **stack, unsigned int num)
{
}
