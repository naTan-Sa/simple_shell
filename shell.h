#ifndef SHELL_H
#define SHELL_H

extern char **environ;

void run_command(char *line, char *shell_name);
char **split_line(char *line);
char *my_strdup(const char *str);
size_t my_strlen(const char *str);

#endif
