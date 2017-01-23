#include "monty.h"

/**
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;

	(void) line_num;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
		(*stack)->prev = new_node;
	new_node->next = *stack;
	new_node->n = push_value;
	new_node->prev = NULL;
	*stack = new_node;
}
**/

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	(void) line_num;
	walker = *stack;
	while (walker != NULL)
	{
		printf("%d\n", walker->n);
		walker = walker->next;
	}
}

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *kill_node, *mover;

	mover = *stack;
	if (mover == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_num);
		opcode_return = 1;
	}
	if (opcode_return != 1)
	{
		kill_node = mover;
		*stack = mover->next;
		mover->prev = NULL;
		free(kill_node);
	}
}

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;
	int tmp;

	walker = *stack;
	if (walker->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		opcode_return = 1;
	}
	if (opcode_return != 1)
	{
		tmp = walker->n;
		walker->n = walker->next->n;
		walker->next->n = tmp;
	}
}

void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_num);
		opcode_return = 1;
	}
	if (opcode_return != 1)
	{
		printf("%d\n", (*stack)->n);
	}
}
