#include "monty.h"

void pchar(stack_t **stack, unsigned int line_num)
{
	if (*stack != NULL)
	{
		if ((*stack)->n < 0 || (*stack)->n > 127)
		{
			printf("L%u: can't pchar, value out of range\n", line_num);
			opcode_return = 1;
		}
		if (opcode_return == 0)
		{
			putchar((*stack)->n);
			putchar('\n');
		}
	}
	else
	{
		printf("L%u: can't pchar, stack empty\n", line_num);
		opcode_return = 1;
	}
}

void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	(void) line_num;
	if (*stack != NULL)
	{
		walker = *stack;
		while (walker != NULL && walker->n > 0 && walker->n <= 127)
		{
			putchar(walker->n);
			walker = walker->next;
		}
	}
	putchar('\n');
}
