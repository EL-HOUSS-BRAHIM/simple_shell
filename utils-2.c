#include "shell.h"
/**
 * _atoi - Convert a string to an integer.
 * @s: The string to convert.
 *
 * Return: The integer value of the string.
 */
int _atoi(const char *s)
{
int result = 0;
int sign = 1;
int i = 0;
if (s[0] == '-')
{
sign = -1;
i++;
}
for (; s[i] != '\0'; i++)
{
result = result * 10 + (s[i] - '0');
}
return (sign * result);
}
/**
 * _isspace - Check if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if it's a whitespace character, 0 otherwise.
 */
int _isspace(int c)
{
return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}
/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
size_t len = 0;
while (str[len] != '\0')
{
len++;
}
return len;
}
/**
 * count_tokens - Count the number of tokens in a string.
 * @line: The input string.
 *
 * Return: The number of tokens.
 */
int count_tokens(const char *line)
{
int count = 0;
int is_token = 0;
while (*line)
{
if (_isspace(*line))
{
is_token = 0;
}
else if (!is_token)
{
is_token = 1;
count++;
}
line++;
}
return (count);
}
