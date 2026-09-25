#include "shell.h"

/**
 * run_command - fork, execute a command and wait for the child
 * @args: NULL-terminated array: args[0] is the command,
 *        the rest are its arguments
 * @shell_name: name used when printing errors
 *
 * Return: nothing
 */
void run_command(char **args, char *shell_name)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		execve(args[0], args, environ);

		print_str(STDERR_FILENO, shell_name);
		print_str(STDERR_FILENO, ": 1: ");
		print_str(STDERR_FILENO, args[0]);
		print_str(STDERR_FILENO, ": not found\n");
		exit(127);
	}

	wait(NULL);
}
