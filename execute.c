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
int run_command(char *path, char **args, char *shell_name)
{
	pid_t pid;
	int wstatus;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		execve(path, args, environ);
		perror(shell_name);
		free(path);
		free(args);
		exit(127);
	}

	wait(&wstatus);
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (1);
}

/**
 * handle_command - finds a command in PATH and runs it
 * @args: NULL-terminated argument array (args[0] is the command)
 * @shell_name: name used when printing errors
 *
 * Return: 127 if not found, otherwise the command's exit status
 */
int handle_command(char **args, char *shell_name)
{
	char *full;
	int status;

	full = find_path(args[0]);
	if (full == NULL)
	{
		print_not_found(shell_name, args[0]);
		return (127);
	}

	status = run_command(full, args, shell_name);
	free(full);

	return (status);
}
