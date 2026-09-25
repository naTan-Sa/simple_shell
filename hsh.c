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
	char *full;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_str(STDOUT_FILENO, "$ ");

		read = getline(&line, &size, stdin);
		if (read == -1)
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = split_line(line);
		if (args == NULL)
			continue;

		if (args[0] != NULL)
		{
			full = find_path(args[0]);
			if (full == NULL)
				print_not_found(argv[0], args[0]);
			else
			{
				run_command(full, args, argv[0]);
				free(full);
			}
		}

		free(args);
	}

	if (isatty(STDIN_FILENO))
		print_str(STDOUT_FILENO, "\n");

	free(line);

	return (0);
}
