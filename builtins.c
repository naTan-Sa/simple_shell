#include "shell.h"

/**
 * print_env - prints every environment variable, one per line
 *
 * Return: always 0 (success)
 */

int print_env(void)
{
	int i;

	if (environ == NULL)
		return (0);

	for (i = 0; environ[i] != NULL; i++)
	{
		print_str(STDOUT_FILENO, environ[i]);
		print_str(STDOUT_FILENO, "\n");
	}

	return (0);
}
