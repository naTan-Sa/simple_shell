#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/*
 * Task 0.1 - Basic shell:
 * prompt -> read -> fork -> execve -> wait -> repeat
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t read;
	pid_t pid;
	char *args[2];

	(void)argc;
	(void)argv;

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

		pid = fork();
		
		if (pid == -1)
		{
			perror("fork");
			break;
		}
		
		if (pid == 0)
		{
			args[0] = line;
			args[1] = NULL;

			execve(line, args, environ);

			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], line);
			exit(127);
		}
		else
		{
			wait(NULL);
		}
	
	}

	free(line);

	return(0);
}
