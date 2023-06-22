#include "monty.h"

/**
 * monty_nop - does absolutely nothing for the Monty opcode 'nop'
 * @stack: pointer to the head of a stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 *
 * Return: void
 */

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * monty_rotl - rotates the top value of a stack_t linked list to the bottom
 * @stack: pointer to the head of a stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 *
 * Return: void
 */

void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		return;
	}

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}


/**
 * monty_rotr - rotates the bottom value of a stack_t linked list to the top
 * @stack: pointer to the head of a stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 *
 * Return: void
 */

void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		return;
	}

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}


/**
 * monty_pstr - prints the string contained in a stack_t linked list
 * @stack: pointer to the head of a stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 *
 * Return: void
 */

void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}


/**
 * monty_pchar - prints the character in the top value
 *               node of a stack_t linked list
 * @stack: pointer to the head of a stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 *
 * Return: void
 */

void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
					"value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
