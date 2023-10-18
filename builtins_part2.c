#include "shell.h"
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