#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"


/**
 * run_command - fork, execute a command and wait for the child
 * @line: command to execute
 * @shell_name: name used when printing errors
 *
 * Return: nothing
 */
void run_command(char *line, char *shell_name)
{
	pid_t pid;
	char *args[2];

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		args[0] = line;
		args[1] = NULL;

		execve(line, args, environ);

		fprintf(stderr, "%s: 1: %s: not found\n", shell_name, line);
		exit(127);
	}

	wait(NULL);
}

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
	size_t size = 0;
	ssize_t read;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
		read = getline(&line, &size, stdin);

		if (read == -1)
			break;
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		run_command(line, argv[0]);
	}

	free(line);

	return (0);
}
