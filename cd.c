#include "shell.h"
/**
 * change_directory - Change the current working directory.
 * @path: The path to the directory to change to.
 *
 * Return: 0 on success, -1 on failure.
 */
int change_directory(char *path)
{
if (path == NULL)
{
fprintf(stderr, "cd: missing argument\n");
return (-1);
}
if (chdir(path) != 0)
{
perror("cd");
return (-1);
}
return (0);
}
