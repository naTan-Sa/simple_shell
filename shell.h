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
void print_not_found(char *shell_name, char *cmd);
void run_command(char *path, char **args, char *shell_name);

/* parse.c */
int count_words(char *str);
char **split_line(char *line);

/* str_utils.c */
size_t my_strlen(const char *str);
char *my_strdup(const char *str);
void print_str(int fd, const char *str);
int my_strncmp(const char *s1, const char *s2, size_t n);

/* path.c */
char *_getenv(const char *name);
char *build_path(const char *dir, const char *cmd);
int has_slash(const char *str);
char *find_path(char *cmd);

#endif
