#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define TOKEN_SIZE 64
#define BUFSIZE 1024
extern char **environ;

/* main.c */
void start_shell(char **env);

/* prompt.c */
void display_prompt(void);
char *read_input(void);

/* execute.c */
int execute_command(char **args, char ***env);
int is_builtin(char *command);
void handle_path(char **args);
char *find_command(const char *command, char **directories);
void handle_child(char **args, char **env);

/* helper.c */
int count_tokens(char *line, char *delimiters);
void free_tokens(char **tokens);
char *str_concat(const char *s1, const char *s2);
char *str_copy(const char *str);

/* builtins.c */
int execute_builtin(char **args, char ***env);
int handle_exit(char **args);
int handle_env(char **env);
int handle_setenv(char ***env, char **args);
int handle_unsetenv(char ***env, char **args);
int handle_cd(char **args, char ***env);

/* environ.c */
char *get_env_value(char **env, const char *name);
void set_env_value(char ***env, const char *name, const char *value);
void unset_env_variable(char ***env, const char *name);

/* getline.c */
ssize_t _getline(char **line, size_t *len, FILE *stream);

/* str_funcs.c */
char **tokenize(char *line, char *delimiters);
char *trim_whitespace(char *str);
char *replace_variables(char *line, char **env);

/* utility_funcs.c */
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
int _atoi(const char *str);
void _puts(const char *str);
int _putchar(char c);
char *_getenv(const char *name);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
void *_memcpy(void *dest, const void *src, size_t n);

#endif /* SHELL_H */
