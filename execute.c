#include "shell.h"

/**
 * execute_command - Execute a command with arguments
 * @args: An array of strings representing the command and its arguments
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **args)
{
    pid_t child_pid;
    int status;

    if (args == NULL || args[0] == NULL)
        return (0);

    if (is_builtin(args[0]))
    {
      status = execute_builtin(args, env);
        return (status);
    }

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("execute_command");
        return (-1);
    }

    if (child_pid == 0)
    {
        handle_child(args, environ);
        _exit(EXIT_FAILURE);
    }
    else
    {
        wait(&status);
        if (WIFEXITED(status))
            return (WEXITSTATUS(status));
    }

    return (-1);
}

/**
 * is_builtin - Check if a command is a built-in shell command
 * @command: The command to check
 *
 * Return: 1 if the command is built-in, 0 otherwise
 */
int is_builtin(char *command)
{
    char *builtins[] = { "exit", "env", "setenv", "unsetenv", "cd", "alias", NULL };
    int i = 0;

    while (builtins[i])
    {
        if (_strcmp(command, builtins[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}

/**
 * handle_path - Handle the PATH environment variable for executing commands
 * @args: An array of strings representing the command and its arguments
 */
void handle_path(char **args)
{
    char *path = _getenv("PATH");
    char **directories;
    char *full_path = NULL;

    if (path == NULL)
    {
        perror("handle_path");
        return;
    }

    directories = tokenize(path, ":");
    if (directories == NULL)
    {
        perror("handle_path");
        return;
    }

    full_path = find_command(args[0], directories);
    if (full_path != NULL)
    {
        args[0] = full_path;
        free_tokens(directories);
        return;
    }

    free_tokens(directories);
}

/**
 * handle_child - Handle the child process execution
 * @args: An array of strings representing the command and its arguments
 * @env: The array of environment variables
 */
void handle_child(char **args, char **env)
{
    handle_path(args);

    if (execve(args[0], args, env) == -1)
    {
        perror("handle_child");
        _exit(EXIT_FAILURE);
    }
}
