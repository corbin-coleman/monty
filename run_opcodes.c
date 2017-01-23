#include "monty.h"

int opcode_return = 0;

int check_codes(char *command, stack_t **stack, size_t line_num)
{
	instruction_t opcodes[] = {
		{"rotr", rotr},
		{"rotl", rotl},
		{"pstr", pstr},
		{"pchar", pchar},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{NULL, NULL}
	};
	size_t i;

	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(command, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_num);
			return (opcode_return);
		}
		i++;
	}
	printf("L%lu: unkown instruction %s\n", line_num, command);
	return (1);
}
