#include "shell.h"
/**
 * _putchar - Write a character to stdout.
 * @c: The character to write.
 * Return: The value of write.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the variable to retrieve.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
int i;
size_t name_len = _strlen(name);
for (i = 0; environ[i]; i++)
{
if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
{
return (environ[i] + name_len + 1);
}
}
return (NULL);
}
/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to append to dest.
 *
 * Return: The concatenated string.
 */
char *_strcat(char *dest, const char *src)
{
int dest_len = _strlen(dest);
int i;
for (i = 0; src[i] != '\0'; i++)
{
dest[dest_len + i] = src[i];
}
dest[dest_len + i] = '\0';
return (dest);
}
/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: The duplicated string.
 */
char *_strdup(const char *str)
{
int len = _strlen(str);
char *dup = (char *)malloc(len + 1);
if (dup == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
_strcpy(dup, str);
return (dup);
}
