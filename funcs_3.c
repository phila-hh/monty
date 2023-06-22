#include "monty.h"

/**
 * monty_stack - converts a queue to a stack
 * @stack: pointer to the head of a stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 *
 * Return: void
 */

void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}


/**
 * monty_queue - converts a stack to a queue.
 * @stack: pointer to the head of a stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 *
 * Return: void
 */

void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
