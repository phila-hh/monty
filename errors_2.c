#include "monty.h"

/**
 * usage_error - prints usage error messages
 *
 * Return: Always (EXIT_FAILURE)
 */

int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");

	return (EXIT_FAILURE);
}


/**
 * unknown_op_error - prints unknown instruction error messages
 * @opcode: Opcode where the error originated
 * @line_number: line number in Monty bytecodes file where error originated
 *
 * Return: Always (EXIT_FAILURE)
 */

int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);

	return (EXIT_FAILURE);
}


/**
 * malloc_error - prints malloc error messages
 *
 * Return: Always (EXIT_FAILURE)
 */

int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");

	return (EXIT_FAILURE);
}


/**
 * f_open_error - prints file opening error messages with file name
 * @filename: name of the file failed to open
 *
 * Return: Always (EXIT_FAILURE)
 */

int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);

	return (EXIT_FAILURE);
}


/**
 * no_int_error - prints invalid monty_push argument error messages
 * @line_number: line number in Monty bytecodes file where error originated
 *
 * Return: Always (EXIT_FAILURE)
 */

int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);

	return (EXIT_FAILURE);
}
