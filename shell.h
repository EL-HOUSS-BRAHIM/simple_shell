#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#define UNUSED(x) (void)(x)
/* Global environment variable */
extern char **environ;
/* Function prototypes */
char *read_line(void);
char **parse_line(char *line);
int execute(char **args);
void free_args(char **args);
/* Task 0: Betty would be proud */
int betty_check(char *filename);
/* Task 3: Simple shell 0.3 */
char *find_command(char *command);
int is_executable(char *path);
/* Task 4: Simple shell 0.4 */
void exit_shell(void);
/* Task 5: Simple shell 1.0 */
void print_environment(void);
/* Task 6: Simple shell 0.1.1 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/* Task 7: Simple shell 0.2.1 */
char *_strtok(char *str, const char *delim);
/* Task 8: Simple shell 0.4.1 */
int exit_status(char **args);
/* Task 10: cd (Advanced) */
int change_directory(char *path);
/* Task 11: ; (Advanced) */
int handle_semicolon(char *line);
/* Task 12: && and || (Advanced) */
int handle_logical_operators(char *line);
/* Task 16: File as input (Advanced) */
int batch_mode(char *filename);
/* Struct for alias commands (Task 13: alias) */
typedef struct Alias
{
    char *name;
    char *value;
    struct Alias *next;
} Alias;
void add_alias(Alias **alias_list, char *name, char *value);
void print_aliases(Alias *alias_list);
/* Struct for variables (Task 14: Variables) */
typedef struct Variable
{
    char *name;
    char *value;
    struct Variable *next;
} Variable;
void add_variable(Variable **variable_list, char *name, char *value);
char *expand_variables(char *line, Variable *variable_list);
void print_variables(Variable *variable_list);
/* Struct for comments (Task 15: Comments) */
typedef struct Comment
{
    char *text;
    struct Comment *next;
} Comment;
void add_comment(Comment **comment_list, char *text);
void print_comments(Comment *comment_list);
/* Function to remove leading and trailing whitespace */
char *trim_whitespace(char *str);
/* Task 9: setenv and unsetenv */
int setenv(const char *name, const char *value, int overwrite);
int unsetenv(const char *name);
#endif /* SHELL_H */