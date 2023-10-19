#include "shell.h"
/**
 * betty_check - Check a file for Betty coding style compliance.
 * @filename: The name of the file to check.
 *
 * Return: 0 if the file passes Betty checks, -1 otherwise.
 */
int betty_check(char *filename)
{
pid_t child_pid;
int status;
if (filename == NULL)
return (-1);
child_pid = fork();
if (child_pid == -1)
{
perror("fork");
return (-1);
}
if (child_pid == 0)
{
if (execlp("betty", "betty", filename, NULL) == -1)
{
perror("execlp");
_exit(EXIT_FAILURE);
}
}
else
{
waitpid(child_pid, &status, 0);
}
return (status);
}
/**
 * is_executable - Check if a file is executable.
 * @path: The path to the file.
 *
 * Return: 1 if the file is executable, 0 otherwise.
 */
int is_executable(char *path)
{
struct stat st;
if (path == NULL)
return (0);
if (stat(path, &st) == 0)
{
if (st.st_mode & S_IXUSR)
return (1);
}
return (0);
}
/**
 * exit_shell - Exit the shell.
 */
void exit_shell(void)
{
exit(EXIT_SUCCESS);
}
/**
 * exit_status - Exit the shell with a specific status code.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: The exit status code.
 */
int exit_status(char **args)
{
int status = EXIT_SUCCESS;
if (args[1] != NULL)
{
status = _atoi(args[1]);
if (status < 0)
{
fprintf(stderr, "Illegal number: %s\n", args[1]);
return (EXIT_FAILURE);
}
}
exit(status);
}
