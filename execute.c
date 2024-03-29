#include "opcodes.h"


/**
 * execute_file - Executes bytecode instructions from a file
 * @filename: Name of the file containing bytecode instructions
 */
void execute_file(const char *filename) {
	FILE *file;
	char line[MAX_LINE_LENGTH];
	stack_t *stack = NULL;
	char *opcode, *arg;
	int value;

	file = fopen(filename, "r");
	if (file == NULL) {
		fprintf(stderr, "Error: Unable to open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
		{
			continue; /* Ignore empty lines or comments */
		}

		if (strcmp(opcode, "push") == 0)
		{
			if (arg == NULL)
			{
				fprintf(stderr, "Error: Missing argument for push\n");
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, 0);
		}
		else
		{
			fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
}
