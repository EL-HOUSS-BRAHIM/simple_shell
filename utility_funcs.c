#include "shell.h"
/**
 * _strlen - Calculate the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
int len = 0;
if (s == NULL)
return (0);
while (s[len] != '\0')
len++;
return (len);
}
/**
 * _strcmp - Compare two strings
 * @s1: The first input string
 * @s2: The second input string
 *
 * Return: 0 if the strings are equal, a negative value if s1 < s2,
 * and a positive value if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
int i = 0;
if (s1 == NULL || s2 == NULL)
return (-1);
while (s1[i] && s2[i] && s1[i] == s2[i])
i++;
return (s1[i] - s2[i]);
}
/**
 * _atoi - Convert a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer value of the string.
 */
int _atoi(const char *str)
{
int result = 0;
int sign = 1;
int i = 0;
if (str[0] == '-')
{
sign = -1;
i++;
}
for (; str[i] != '\0'; ++i)
{
if (str[i] >= '0' && str[i] <= '9')
{
result = result * 10 + (str[i] - '0');
}
else
{
break;
}
}
return (result *sign);
}
/**
 * _puts - Print a string to stdout.
 * @str: The string to print.
 */
void _puts(const char *str)
{
while (*str)
{
_putchar(*str);
str++;
}
}
