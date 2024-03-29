#include "opcodes.h"

/**
 * push - Pushes an integer onto the stack
 * @stack: Pointer to the top of the stack
 * @value: Value to push onto the stack
 */
void push(stack_t **stack, int value) {
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL) {
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL) {
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - Prints all elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void pall(stack_t **stack, unsigned int line_number) {
	stack_t *current = *stack;
	printf("Printing all elements of the stack at line %u:\n", line_number);
	while (current != NULL) {
		printf("%d\n", current->n);
		current = current->next;
	}
}

