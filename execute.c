#include "shell.h"

/**
 * print_not_found - prints the "command not found" error
 * @shell_name: name of the shell (argv[0])
 * @cmd: the command that was not found
 *
 * Return: nothing
 */
void print_not_found(char *shell_name, char *cmd)
{
	print_str(STDERR_FILENO, shell_name);
	print_str(STDERR_FILENO, ": 1: ");
	print_str(STDERR_FILENO, cmd);
	print_str(STDERR_FILENO, ": not found\n");
}

/**
 * run_command - fork, execute a command and wait for the child
 * @args: NULL-terminated array: args[0] is the command,
 *        the rest are its arguments
 * @shell_name: name used when printing errors
 *
 * Return: nothing
 */
void run_command(char *path, char **args, char *shell_name)
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
		execve(path, args, environ);
		perror(shell_name);
		free(path);
		free(args);
		exit(127);
	}

	wait(NULL);
}
