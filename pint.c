#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the bytecode file
 *
 * Description: If the stack is not empty, prints the value
 * at the top of the stack followed by a new line. If the stack
 * is empty, prints an error message and exits with EXIT_FAILURE.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
