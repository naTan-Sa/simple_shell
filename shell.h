#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* execute.c */
void run_command(char **args, char *shell_name);

/* parse.c */
int count_words(char *str);
char **split_line(char *line);

/* str_utils.c */
size_t my_strlen(const char *str);
char *my_strdup(const char *str);
void print_str(int fd, const char *str);

#endif
