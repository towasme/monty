#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

extern int num_error;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void read_textfile(char *filename, stack_t **stack);
char **tokenize(char *args);
void compare_string(char *buff, stack_t **stack, int contador);

void op_push(stack_t **stack, unsigned int num);
void op_pop(stack_t **stack, unsigned int num);
void op_pall(stack_t **stack, unsigned int num);
void op_pint(stack_t **stack, unsigned int num);
void op_swap(stack_t **stack, unsigned int num);
void op_add(stack_t **stack, unsigned int num);

#endif
