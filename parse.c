#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * my_strlen - calculates the length of a string
 * @str: the string to measure
 *
 * Return: the length of the string
 */
size_t my_strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * my_strdup - creates a duplicate of a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL on failure
 */
char *my_strdup(const char *str)
{
	char *copy;
	size_t len;
	size_t i;

	len = my_strlen(str);

	copy = malloc(len + 1);

	if (copy == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	return (copy);
}

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
