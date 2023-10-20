#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

typedef struct list_s
{
    struct list_s *next;
    char *str;
    int num;
} list_t;

typedef struct shell_info
{
    int read_fd;
    list_t *alias;
    list_t *env;
    char **argv;
    int status;
    int err_num;
    int cmd_buf_type;
    char **cmd_buf;
    int linecount_flag;
    int histcount;
} ShellInfo;

void sigintHandler(int sig_num);

ssize_t get_input(ShellInfo *info);

ssize_t input_buf(ShellInfo *info, char **buf, size_t *len);

ssize_t read_buf(ShellInfo *info, char *buf, size_t *i);

int my_shell(ShellInfo *info, char **argv);

void populate_environment_list(ShellInfo *info);

void read_shell_history(ShellInfo *info);

char *_strchr(const char *s, int c);

size_t _strlen(const char *s);

void _eputs(const char *str);

void _eputchar(char c);

int _erratoi(const char *str);

void _setenv(ShellInfo *info, const char *name, const char *value);

char *_getenv(ShellInfo *info, const char *name);

void print_error(ShellInfo *info, const char *msg);

void build_history_list(ShellInfo *info, char *cmd, int count);

void remove_comments(char *str);

void free_list(list_t *head);

#endif /* MY_SHELL_H */
