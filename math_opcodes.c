#include "monty.h"

void add(stack_t **stack, unsigned int line_num)
{
        stack_t *walker;

        walker = *stack;
        if (walker->next == NULL)
        {
                printf("L%u: can't add, stack too short\n", line_num);
		opcode_return = 1;
        }
	if (opcode_return != 1)
	{
		walker->next->n += walker->n;
		pop(stack, line_num);
	}
}

void sub(stack_t **stack, unsigned int line_num)
{
        stack_t *walker;

        walker = *stack;
        if (walker->next == NULL)
        {
                printf("L%u: can't sub, stack too short\n", line_num);
		opcode_return = 1;
        }
	if (opcode_return != 1)
	{
		walker->next->n -= walker->n;
		pop(stack, line_num);
	}
}

void _div(stack_t **stack, unsigned int line_num)
{
        stack_t *walker;

        walker = *stack;
        if (walker->next == NULL)
        {
                printf("L%u: can't div, stack too short\n", line_num);
		opcode_return = 1;
        }
	if (walker->n == 0 && opcode_return != 1)
	{
		printf("L%u: division by zero\n", line_num);
		opcode_return = 1;
	}
	if (opcode_return != 1)
	{
		walker->next->n /= walker->n;
		pop(stack, line_num);
	}
}

void mul(stack_t **stack, unsigned int line_num)
{
        stack_t *walker;

        walker = *stack;
        if (walker->next == NULL)
        {
                printf("L%u: can't mul, stack too short\n", line_num);
		opcode_return = 1;
        }
	if (opcode_return != 1)
	{
		walker->next->n *= walker->n;
		pop(stack, line_num);
	}
}

void mod(stack_t **stack, unsigned int line_num)
{
        stack_t *walker;

        walker = *stack;
        if (walker->next == NULL)
        {
                printf("L%u: can't mod, stack too short\n", line_num);
		opcode_return = 1;
        }
	if (walker->n == 0 && opcode_return != 1)
	{
		printf("L%u: division by zero\n", line_num);
		opcode_return = 1;
	}
	if (opcode_return != 1)
	{
		walker->next->n %= walker->n;
		pop(stack, line_num);
	}
}
