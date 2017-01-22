#include "monty.h"

int check_codes(char *command, stack_t **stack, size_t line_num)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall}
	};
	size_t i, arr_size;

	arr_size = 2;
	i = 0;
	while (i < arr_size)
	{
		if (strcmp(command, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_num);
			return (0);
		}
		i++;
	}
	return (2);
}
