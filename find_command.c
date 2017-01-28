#include "monty.h"

char *find_command(char *line, stack_t **stack, unsigned int line_num)
{
	char *command, *push_arg;

	command = strtok(line, "\n\t\r ");
	if (command == NULL || command[0] == '#')
		command = "nop";
	if (strcmp(command, "push") == 0)
	{
		command = "nop";
		push_arg = strtok(NULL, "\n \t\r");
		if (int_check(push_arg) == 0)
		{
			if (ret_and_q.queue_val == 0)
				add_node(stack, atoi(push_arg));
			else
				add_node_end(stack, atoi(push_arg));
		}
		else
		{
			printf("L%u: usage: push integer\n", line_num);
			ret_and_q.opcode_return = 1;
			return (command);
		}
	}
	if (strcmp(command, "stack") == 0)
	{
		command = "nop";
		ret_and_q.queue_val = 0;
		return (command);
	}
	if (strcmp(command, "queue") == 0)
	{
		command = "nop";
		ret_and_q.queue_val = 1;
		return (command);
	}
	return (command);
}

int int_check(char *push_arg)
{
	int i;

	if (push_arg == NULL)
		return (1);
	i = 0;
	while (push_arg[i] != '\0')
	{
		if (isalpha(push_arg[i]))
			return (1);
		i++;
	}
	return (0);
}

void add_node(stack_t **stack, int push_value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		if (*stack != NULL)
			(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->n = push_value;
		new_node->prev = NULL;
		*stack = new_node;
	}
}

void add_node_end(stack_t **stack, int push_value)
{
	stack_t *new_node;
	stack_t *walker;

	walker = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		while(walker != NULL && walker->next != NULL)
			walker = walker->next;
		new_node->n = push_value;
		new_node->next = NULL;
		new_node->prev = walker;
		if (walker != NULL)
			walker->next = new_node;
		else
			*stack = new_node;
	}
}
