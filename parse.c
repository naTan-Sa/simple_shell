#include "shell.h"

/**
 * split_line - splits a line into an array of words
 * @line: the string to split (will be modified)
 *
 * Return: NULL-terminated array of words, or NULL on failure
 */

char **split_line(char *line)
{
	char **tokens = NULL;
	int count = 0;
	int i = 0;
	char *copy, *token;

	copy = my_strdup(line);
	if (copy == NULL)
		return (NULL);

	token = strtok(copy, " \t");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " \t");
	}
	free(copy);

	tokens = malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
		return (NULL);

	token = strtok(line, " \t");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	tokens[i] = NULL;

	return (tokens);
}
