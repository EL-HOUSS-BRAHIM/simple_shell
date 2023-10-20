#include "shell.h"
/**
 * new_strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *new_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * new_strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *new_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *new_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void new_puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_new_putchar(str[i]);
		i++;
	}
}

/**
 * _new_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _new_putchar(char c)
{
	static int i;
	static char buf[NEW_NEW_WRITE_BUF_SIZE];

	if (c == NEW_BUF_FLUSH || i >= NEW_NEW_WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != NEW_BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
