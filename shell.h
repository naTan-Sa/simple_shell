#ifndef SHELL_H
#define SHELL_H

extern char **environ;

void run_command(char *line, char *shell_name);

#endif
