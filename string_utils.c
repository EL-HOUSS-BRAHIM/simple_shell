#include "shell.h"
/**
 * _getline - A custom getline function to read a line from a stream.
 * @lineptr: A pointer to the buffer where the line is stored.
 * @n: A pointer to the size of the buffer.
 * @stream: The input stream to read from.
 *
 * Return: The number of characters read, or -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
if (lineptr == NULL || n == NULL)
return (-1);
nread = getline(&line, &len, stream);
if (nread == -1)
{
if (line)
free(line);
return (-1);
}
if (*lineptr)
{
free(*lineptr);
}
*lineptr = line;
*n = len;
return (nread);
}
/**
 * _strtok - A custom strtok function that splits a string into tokens.
 * @str: The string to split.
 * @delim: The delimiters to use for splitting.
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
static char *next = NULL;
char *token;
if (str)
next = str;
if (!next)
return (NULL);
token = next + strspn(next, delim);
next = token + strcspn(token, delim);
if (next == token)
{
next = NULL;
return (NULL);
}
next[0] = '\0';
next++;
return (token);
}
/**
 * trim_whitespace - Remove leading and trailing whitespace from a string.
 * @str: The string to trim.
 *
 * Return: A pointer to the trimmed string.
 */
char *trim_whitespace(char *str)
{
char *end;
if (str == NULL)
return (NULL);
while (isspace((unsigned char)*str))
str++;
if (*str == 0)
return str;
end = str + strlen(str) - 1;
while (end > str && isspace((unsigned char)*end))
end--;
end[1] = '\0';
return str;
}