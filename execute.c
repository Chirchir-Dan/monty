#include "monty.h"



/**
 * execute_file - Executes bytecode instructions from a file
 * @filename: Name of the file containing bytecode instructions
 */
void execute_file(const char *filename)
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	stack_t *stack = NULL;
	char *opcode, *arg;
	int value;
	unsigned int line_number = 0;


	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
		{
			continue; /* Ignore empty lines or comments */
		}
		if (strcmp(opcode, "push") == 0)
		{
			value = atoi(arg);
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack);
		else if (strcmp(opcode, "pint") == 0)
			pint(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
}
