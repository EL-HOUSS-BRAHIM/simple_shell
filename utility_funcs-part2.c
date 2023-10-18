#include "shell.h"
extern char **environ;
/**
 * _memcpy - Copy memory area.
 * @dest: Destination memory area.
 * @src: Source memory area.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to the destination memory area.
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
char *d = (char *)dest;
const char *s = (const char *)src;
while (n--)
{
*d++ = *s++;
}
return dest;
}
/**
 * find_command - Find the full path of a command in the given directories.
 * @command: The name of the command to find.
 * @directories: An array of directory paths to search for the command.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *find_command(const char *command, char **directories)
{
char *path = NULL;
char *token = NULL;
char *temp = NULL;
int i = 0;
while (directories[i] != NULL)
{
temp = strdup(directories[i]);
if (temp == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
token = strtok(temp, ":");
while (token != NULL)
{
path = malloc(strlen(token) + strlen(command) + 2);
if (path == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
sprintf(path, "%s/%s", token, command);
if (access(path, F_OK) == 0)
{
free(temp);
return path;
}
free(path);
token = strtok(NULL, ":");
}
free(temp);
i++;
}
return NULL;
}