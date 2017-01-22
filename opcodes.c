#include "monty.h"

void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;

	(void) line_num;
	new_node = malloc(sizeof(stack_t *));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->next = *stack;
	new_node->n = push_value;
	*stack = new_node;
}

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
