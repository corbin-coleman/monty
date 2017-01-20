#include "monty.h"

int main(int argc, char *argv[])
{
	FILE* file;
	char *line, **args;
	int checker;
	size_t size, line_num;
	ssize_t read = 0;

	line = NULL;
	args = NULL;
	size = 0;
	line_num = 1;
	if (argc != 2)
		exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &size, file);
	while (read != -1)
	{
		args = make_tokes(line);
		if (args == NULL)
		{
			printf("Error: malloc failed\n");
			free(args);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		checker = check_codes(args);
		if (checker == 1)
		{
			printf("L%lu: unknown instruction %s\n", line_num, args[0]);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		line_num++;
		read = getline(&line, &size, file);
	}
	free(line);
	fclose(file);
	return (0);
}

char **make_tokes(char *line)
{
	char **args;
	char *arg;
	int i = 0;

	args = malloc(sizeof(char *) * 3);
	if (args == NULL)
		return (args);
	arg = strtok(line, "\n \t\r");
	while (arg != NULL)
	{
		args[i] = arg;
		arg = strtok(NULL, "\n \t\r");
		i++;
	}
	return (args);
}

int check_codes(char **args)
{
	char *opcodes = "push";
	size_t i, arr_size;

	arr_size = 1;
	i = 0;
	while (i < arr_size)
	{
		if (strcmp(args[0], opcodes) == 0)
			printf("Pushing\n");
		else
			return (1);
		i++;
	}
	return (0);
}
