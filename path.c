#include "shell.h"


/**
 * _getenv - finds the value of an environment variable
 * @name: variable name
 *
 * Return: pointer to the value inside environ, or NULL if not found
 */
char *_getenv(const char *name)
{
	size_t len;
	int i;

	if (name == NULL || environ == NULL)
		return (NULL);

	len = my_strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (my_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}

	return (0);
}


/**
 * build_path - joins a directory and a command with a '/'
 * @dir: directory, e.g. "/usr/bin"
 * @cmd: command, e.g. "ls"
 *
 * Return: newly allocated "dir/cmd", or NULL on failure
 */
char *build_path(const char *dir, const char *cmd)
{
	char *full;
	size_t dlen, clen, i, j;

	dlen = my_strlen(dir);
	clen = my_strlen(cmd);

	full = malloc(dlen + clen + 2);
	if (full == NULL)
		return (NULL);

	for (i = 0; i < dlen; i++)
		full[i] = dir[i];
	full[i] = '/';
	i++;
	for (j = 0; j < clen; j++)
		full[i + j] = cmd[j];
	full[i + j] = '\0';

	return (full);
}


/**
 * has_slash - checks whether a string contains a '/'
 * @str: the string
 *
 * Return: 1 if it does, 0 otherwise
 */
int has_slash(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}


/**
 * find_path - finds the full path of a command
 * @cmd: the command typed by the user
 *
 * Return: newly allocated full path , or NULL
 */
char *find_path(char *cmd)
{
	char *path, *copy, *dir, *full;

	if (has_slash(cmd))
	{
		if (access(cmd, X_OK) == 0)
			return (my_strdup(cmd));
		return (NULL);
	}

	path = _getenv("PATH");

	if (path == NULL || path[0] == '\0')
		return (NULL);

	copy = my_strdup(path);
	if (copy == NULL)
		return (NULL);

	dir = strtok(copy, ":");

	while (dir != NULL)
	{
		full = build_path(dir, cmd);

		if (full == NULL)
			break;
		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (full);
		}
		free(full);
		dir = strtok(NULL, ":");
	}
	free(copy);
	return (NULL);
}



