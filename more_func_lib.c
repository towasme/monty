#include "monty.h"

/**
 * op_sub - subtracts
 * @stack: stack
 * @num: Line number of the instruction (void)
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int num)
{
	stack_t *aux = *stack;
	int sub_num = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	sub_num = (*stack)->n;
	(*stack)->next->n -= sub_num;
	*stack = aux->next;
	(*stack)->prev = NULL;
	free(aux);
}


