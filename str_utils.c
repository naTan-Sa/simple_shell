#include "shell.h"

/**
 * my_strlen - returns the length of a string
 * @str: the string
 *
 * Return: number of characters before '\0'
 */
size_t my_strlen(const char *str)
{
	size_t i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * my_strdup - duplicates a string in newly allocated memory
 * @str: the string to copy
 *
 * Return: pointer to the copy, or NULL on failure
 */
char *my_strdup(const char *str)
{
	char *copy;
	size_t len, i;

	if (str == NULL)
		return (NULL);

	len = my_strlen(str);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[len] = '\0';

	return (copy);
}

/**
 * print_str - writes a string to a file descriptor
 * @fd: where to write (STDOUT_FILENO or STDERR_FILENO)
 * @str: the string to write
 *
 * Return: nothing
 */
void print_str(int fd, const char *str)
{
	write(fd, str, my_strlen(str));
}

/**
 * my_strncmp - compares two strings up to n characters
 * @s1: first string
 * @s2: second string
 * @n: maximum number of characters to compare
 *
 * Return: difference between the first different characters,
 *         or 0 if the strings match within n characters
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	for(i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);

		if (s1[i] == '\0')
			return (0);
	}

	return (0);
}
