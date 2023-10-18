#include "shell.h"
/**
 * _getline - Custom getline function that reads a line from a file stream
 * @line: A pointer to the buffer where the line will be stored
 * @len: A pointer to the size of the buffer
 * @stream: The file stream to read from
 *
 * Return: The number of characters read, or -1 on failure
 */
ssize_t _getline(char **line, size_t *len, FILE *stream)
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t nread;
if (line == NULL || len == NULL)
return (-1);
if (*line == NULL || *len == 0)
{
*line = NULL;
*len = 0;
bufsize = BUFSIZE;
}
else
{
buffer = *line;
bufsize = *len;
}
nread = getline(&buffer, &bufsize, stream);
if (nread == -1)
{
free(buffer);
buffer = NULL;
bufsize = 0;
}
*line = buffer;
*len = bufsize;
return (nread);
}
