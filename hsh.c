#include "shell.h"

/**
 * main - entry point for the simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **args;
	size_t size = 0;
	ssize_t read;
	int status = 0;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_str(STDOUT_FILENO, "$ ");

		read = getline(&line, &size, stdin);
		if (read == -1)
		{
			if(isatty(STDIN_FILENO))
				print_str(STDOUT_FILENO, "\n");
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = split_line(line);
		if (args == NULL)
			continue;

		if (args[0] != NULL && my_strcmp(args[0], "exit") == 0)
		{
			free(args);
			break;
		}

		if (args[0] != NULL)
			status = handle_command(args, argv[0]);

		free(args);
	}

	free(line);

	return (status);
}
