#include "monty.h"

int push_value;

char *find_command(char *line)
{
	char *command, *push_arg;
	command = strtok(line, "\n \t\r");
	if (strcmp(command, "push") == 0)
	{
		push_arg = strtok(NULL, "\n \t\r");
		if (push_arg == NULL)
			return (NULL);
		int_check(push_arg);
	}
	return (command);
}

int int_check(char *push_arg)
{
	int i;

	i = 0;
	while (push_arg[i] != '\0')
	{
		if (isalpha(push_arg[i]))
			return (1);
		i++;
	}
	push_value = atoi(push_arg);
	return (0);
}
