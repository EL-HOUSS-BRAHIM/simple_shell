#include "shell.h"
/**
 * execute - Execute a command with its arguments.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: 0 if successful, -1 on failure.
 */
int execute(char **args)
{
pid_t child_pid;
int status;
if (args == NULL || args[0] == NULL)
return (-1);
child_pid = fork();
if (child_pid == -1)
{
perror("fork");
return (-1);
}
if (child_pid == 0)
{
if (execve(args[0], args, environ) == -1)
{
perror("execve");
free_args(args);
_exit(EXIT_FAILURE);
}
}
else
{
waitpid(child_pid, &status, 0);
}
return (status);
}