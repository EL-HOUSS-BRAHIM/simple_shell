#include "shell.h"
/**
 * read_line - Read a line of input from the user.
 *
 * Return: A pointer to the line of input.
 */
char *read_line(void)
{
char *line = NULL;
size_t len = 0;
if (getline(&line, &len, stdin) == -1)
{
if (feof(stdin))
{
free(line);
return (NULL);
}
perror("getline");
free(line);
exit(EXIT_FAILURE);
}
if (line && line[0] == '\n')
{
free(line);
return (NULL);
}
if (line)
line[_strlen(line) - 1] = '\0';
return (line);
}
