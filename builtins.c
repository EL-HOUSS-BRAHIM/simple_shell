#include "shell.h"

/**
 * execute_builtin - Execute a built-in shell command
 * @args: An array of strings representing the command and its arguments
 * @env: The array of environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int execute_builtin(char **args, char ***env)
{
    if (_strcmp(args[0], "exit") == 0)
        return (handle_exit(args));
    else if (_strcmp(args[0], "env") == 0)
        return (handle_env(*env));
    else if (_strcmp(args[0], "setenv") == 0)
        return (handle_setenv(env, args));
    else if (_strcmp(args[0], "unsetenv") == 0)
        return (handle_unsetenv(env, args));
    else if (_strcmp(args[0], "cd") == 0)
        return (handle_cd(args, env));

    return (-1);
}

/**
 * handle_exit - Handle the exit built-in command
 * @args: An array of strings representing the command and its arguments
 *
 * Return: -1 if the shell should exit, 0 otherwise
 */
int handle_exit(char **args)
{
    int status = 0;

    if (args[1] != NULL)
    {
        status = _atoi(args[1]);
        if (status < 0)
        {
            perror("exit");
            return (0);
        }
    }

    exit(status);
}

/**
 * handle_env - Handle the env built-in command
 * @env: The array of environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int handle_env(char **env)
{
    int i = 0;

    while (env[i])
    {
        _puts(env[i]);
        _putchar('\n');
        i++;
    }

    return (0);
}

/**
 * handle_setenv - Handle the setenv built-in command
 * @env: A pointer to the array of environment variables
 * @args: An array of strings representing the command and its arguments
 *
 * Return: 0 on success, -1 on failure
 */
int handle_setenv(char ***env, char **args)
{
  (void)***env;
    if (args[1] == NULL || args[2] == NULL)
    {
        perror("setenv");
        return (-1);
    }

    if (setenv(args[1], args[2], 1) == -1)
    {
        perror("setenv");
        return (-1);
    }

    return (0);
}

/**
 * handle_unsetenv - Handle the unsetenv built-in command
 * @env: A pointer to the array of environment variables
 * @args: An array of strings representing the command and its arguments
 *
 * Return: 0 on success, -1 on failure
 */
int handle_unsetenv(char ***env, char **args)
{
  (void)***env;
  if (args[1] == NULL)
    {
        perror("unsetenv");
        return (-1);
    }

    if (unsetenv(args[1]) == -1)
    {
        perror("unsetenv");
        return (-1);
    }

    return (0);
}

/**
 * handle_cd - Handle the cd built-in command
 * @args: An array of strings representing the command and its arguments
 * @env: A pointer to the array of environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int handle_cd(char **args, char ***env)
{
    char *home = _getenv("HOME");
    char *oldpwd = _getenv("PWD");
    char *pwd = NULL;
    int status;
    (void)***env;

    if (args[1] == NULL || _strcmp(args[1], "~") == 0)
        status = chdir(home);
    else if (_strcmp(args[1], "-") == 0)
        status = chdir(oldpwd);
    else
        status = chdir(args[1]);

    if (status == -1)
    {
        perror("cd");
        return (-1);
    }

    pwd = getcwd(NULL, 0);
    if (pwd == NULL)
    {
        perror("cd");
        return (-1);
    }

    if (setenv("OLDPWD", oldpwd, 1) == -1 || setenv("PWD", pwd, 1) == -1)
    {
        perror("cd");
        return (-1);
    }

    free(pwd);
    return (0);
}
