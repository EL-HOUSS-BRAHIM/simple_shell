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

/* for new_convert_number() */
#define NEW_CONVERT_LOWERCASE 1
#define NEW_CONVERT_UNSIGNED 2

/* 1 if using system getline() */
#define NEW_USEnew_getline 0
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
int new_new_hsh(new_info_t *, char **);
int new_new_find_builtin(new_info_t *);
void new_new_find_cmd(new_info_t *);
void new_new_fork_cmd(new_info_t *);

/* new_parser.c */
int new_is_cmd(new_info_t *, char *);
char *new_dup_chars(char *, int, int);
char *new_find_path(new_info_t *, char *, char *);

/* new_loop_new_hsh.c */
int new_loopnew_hsh(char **);

/* new_errors.c */
void newnew_eputs(char *);
int newnew_eputchar(char);
int newnew_putfd(char c, int fd);
int newnewnew_putsfd(char *str, int fd);

/* new_string.c */
int newnew_strlen(char *);
int newnew_strcmp(char *, char *);
char *new_new_starts_with(const char *, const char *);
char *newnew_strcat(char *, char *);

/* new_string1.c */
char *newnew_strcpy(char *, char *);
char *newnew_strdup(const char *);
void newnew_puts(char *);
int newnew_putchar(char);

/* new_toem_exits.c */
char *newnew_strncpy(char *, char *, int);
char *new_strncat(char *, char *, int);
char *newnew_strchr(char *, char);

/* new_toem_tokenizer.c */
char **new_new_strtow(char *, char *);
char **new_new_new_strtow2(char *, char);

/* newnew_realloc.c */
char *newnew_memset(char *, char, unsigned int);
void new_new_ffree(char **);
void *newnew_realloc(void *, unsigned int, unsigned int);

/* new_memory.c */
int new_new_bfree(void **);

/* newnew_atoi.c */
int new_new_interactive(new_info_t *);
int new_new_is_delim(char, char *);
int newnew_isalpha(int);
int newnew_atoi(char *);

/* new_errors1.c */
int newnew_erratoi(char *);
void new_new_print_error(new_info_t *, char *);
int new_new_print_d(int, int);
char *new_new_convert_number(long int, int, int);
void new_new_remove_comments(char *);

/* new_builtin.c */
int newnew_myexit(new_info_t *);
int newnew_mycd(new_info_t *);
int newnew_myhelp(new_info_t *);

/* new_builtin1.c */
int newnew_myhistory(new_info_t *);
int newnew_myalias(new_info_t *);

/*newnew_getline.c */
ssize_t new_new_get_input(new_info_t *);
int newnew_getline(new_info_t *, char **, size_t *);
void new_new_sigintHandler(int);

/* new_getinfo.c */
void new_new_clear_info(new_info_t *);
void new_new_set_info(new_info_t *, char **);
void new_new_free_info(new_info_t *, int);

/* new_environ.c */
char *newnew_getenv(new_info_t *, const char *);
int newnew_myenv(new_info_t *);
int newnew_mysetenv(new_info_t *);
int newnew_myunsetenv(new_info_t *);
int new_new_populate_env_list(new_info_t *);

/* newnew_getenv.c */
char **new_get_environ(new_info_t *);
int new_unsetenv(new_info_t *, char *);
int new_setenv(new_info_t *, char *, char *);

/* new_history.c */
char *new_new_get_history_file(new_info_t info);
int new_new_write_history(new_info_t info);
int new_new_read_history(new_info_t info);
int new_new_build_history_list(new_info_t info, char *buf, int linecount);
int new_new_renumber_history(new_info_t info);

/* new_lists.c */
new_list_t *new_new_add_node(new_list_t **, const char *, int);
new_list_t *new_new_new_add_node_end(new_list_t **, const char *, int);
size_t new_new_new_print_list_str(const new_list_t *);
int new_new_delete_node_at_index(new_list_t **, unsigned int);
void new_new_free_list(new_list_t **);

/* new_lists1.c */
size_t new_new_list_len(const new_list_t *);
char **new_new_list_to_strings(new_list_t *);
size_t new_new_print_list(const new_list_t *);
new_list_t *new_node_new_starts_with(new_list_t *, char *, char);
ssize_t new_new_get_node_index(new_list_t *, new_list_t *);

/* new_vars.c */
int new_new_is_chain(new_info_t *, char *, size_t *);
void new_new_check_chain(new_info_t *, char *, size_t *, size_t, size_t);
int new_new_replace_alias(new_info_t *);
int new_new_replace_vars(new_info_t *);
int new_new_replace_string(char **, char *);

#endif
