#ifndef _NEW_SHELL_H_
#define _NEW_SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define NEW_READ_BUF_SIZE 1024
#define NEW_WRITE_BUF_SIZE 1024
#define NEW_BUF_FLUSH -1

/* for command chaining */
#define NEW_CMD_NORM 0
#define NEW_CMD_OR 1
#define NEW_CMD_AND 2
#define NEW_CMD_CHAIN 3

/* for convert_number() */
#define NEW_CONVERT_LOWERCASE 1
#define NEW_CONVERT_UNSIGNED 2

/* 1 if using system getline() */
#define NEW_USE_GETLINE 0
#define NEW_USE_STRTOK 0

#define NEW_HIST_FILE ".new_simple_shell_history"
#define NEW_HIST_MAX 4096

extern char **environ;

/**
 * struct new_liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct new_liststr
{
    int num;
    char *str;
    struct new_liststr *next;
} new_list_t;

/**
 *struct new_passinfo - contains pseudo-arguments to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguments
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd ; chain buffer, for memory management
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct new_passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    new_list_t *env;
    new_list_t *history;
    new_list_t *alias;
    char **environ;
    int env_changed;
    int status;

    char **cmd_buf; /* pointer to cmd ; chain buffer, for memory management */
    int cmd_buf_type; /* CMD_type ||, &&, ; */
    int readfd;
    int histcount;
} new_info_t;

#define NEW_INFO_INIT                   \
{                                      \
    NULL, NULL, NULL, 0, 0, 0, 0, NULL, \
    NULL, NULL, NULL, NULL, 0, 0, NULL,  \
    0, 0, 0                           \
}

/**
 *struct new_builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct new_builtin
{
    char *type;
    int (*func)(new_info_t *);
} new_builtin_table;

/* new_shloop.c */
int new_hsh(new_info_t *, char **);
int new_find_builtin(new_info_t *);
void new_find_cmd(new_info_t *);
void new_fork_cmd(new_info_t *);

/* new_parser.c */
int new_is_cmd(new_info_t *, char *);
char *new_dup_chars(char *, int, int);
char *new_find_path(new_info_t *, char *, char *);

/* new_loop_hsh.c */
int new_loophsh(char **);

/* new_errors.c */
void new_eputs(char *);
int new_eputchar(char);
int new_putfd(char c, int fd);
int new_putsfd(char *str, int fd);

/* new_string.c */
int new_strlen(char *);
int new_strcmp(char *, char *);
char *new_starts_with(const char *, const char *);
char *new_strcat(char *, char *);

/* new_string1.c */
char *new_strcpy(char *, char *);
char *new_strdup(const char *);
void new_puts(char *);
int new_putchar(char);

/* new_toem_exits.c */
char *new_strncpy(char *, char *, int);
char *new_strncat(char *, char *, int);
char *new_strchr(char *, char);

/* new_toem_tokenizer.c */
char **new_strtow(char *, char *);
char **new_strtow2(char *, char);

/* new_realloc.c */
char *new_memset(char *, char, unsigned int);
void new_ffree(char **);
void *new_realloc(void *, unsigned int, unsigned int);

/* new_memory.c */
int new_bfree(void **);

/* new_atoi.c */
int new_interactive(new_info_t *);
int new_is_delim(char, char *);
int new_isalpha(int);
int new_atoi(char *);

/* new_errors1.c */
int new_erratoi(char *);
void new_print_error(new_info_t *, char *);
int new_print_d(int, int);
char *new_convert_number(long int, int, int);
void new_remove_comments(char *);

/* new_builtin.c */
int new_myexit(new_info_t *);
int new_mycd(new_info_t *);
int new_myhelp(new_info_t *);

/* new_builtin1.c */
int new_myhistory(new_info_t *);
int new_myalias(new_info_t *);

/*new_getline.c */
ssize_t new_get_input(new_info_t *);
int new_getline(new_info_t *, char **, size_t *);
void new_sigintHandler(int);

/* new_getinfo.c */
void new_clear_info(new_info_t *);
void new_set_info(new_info_t *, char **);
void new_free_info(new_info_t *, int);

/* new_environ.c */
char *new_getenv(new_info_t *, const char *);
int new_myenv(new_info_t *);
int new_mysetenv(new_info_t *);
int new_myunsetenv(new_info_t *);
int new_populate_env_list(new_info_t *);

/* new_getenv.c */
char **new_get_environ(new_info_t *);
int new_unsetenv(new_info_t *, char *);
int new_setenv(new_info_t *, char *, char *);

/* new_history.c */
char *new_get_history_file(new_info_t info);
int new_write_history(new_info_t info);
int new_read_history(new_info_t info);
int new_build_history_list(new_info_t info, char *buf, int linecount);
int new_renumber_history(new_info_t info);

/* new_lists.c */
new_list_t *new_add_node(new_list_t **, const char *, int);
new_list_t *new_add_node_end(new_list_t **, const char *, int);
size_t new_print_list_str(const new_list_t *);
int new_delete_node_at_index(new_list_t **, unsigned int);
void new_free_list(new_list_t **);

/* new_lists1.c */
size_t new_list_len(const new_list_t *);
char **new_list_to_strings(new_list_t *);
size_t new_print_list(const new_list_t *);
new_list_t *new_node_starts_with(new_list_t *, char *, char);
ssize_t new_get_node_index(new_list_t *, new_list_t *);

/* new_vars.c */
int new_is_chain(new_info_t *, char *, size_t *);
void new_check_chain(new_info_t *, char *, size_t *, size_t, size_t);
int new_replace_alias(new_info_t *);
int new_replace_vars(new_info_t *);
int new_replace_string(char **, char *);

#endif
