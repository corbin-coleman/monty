#include "monty.h"

int main(int argc, char *argv[])
{
	FILE* file;
	char *line, *command;
	size_t size, line_num, checker;
	ssize_t read = 0;
	stack_t *stack;

	stack = NULL;
	line = NULL;
	size = checker = 0;
	line_num = 1;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &size, file);
	while (read != -1)
	{
		command = find_command(line);
		if (command == NULL)
		{
			printf("L%lu: usage: push integer\n", line_num);
			free_and_exit(line, file);
		}
		checker = check_codes(command, &stack, line_num);
		if (checker != 0)
		{
			if (checker == 2)
				printf("L%lu: unkown instruction %s\n", line_num, command);
			free_and_exit(line, file);
		}
		line_num++;
		read = getline(&line, &size, file);
	}
	free(line);
	fclose(file);
	return (0);
}

void free_and_exit(char *line, FILE* file)
{
	free(line);
	fclose(file);
	exit(EXIT_FAILURE);
}
