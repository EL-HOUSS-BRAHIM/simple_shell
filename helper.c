#include "shell.h"
/**
 * count_tokens - Count the number of tokens in a string.
 * @line: The input string.
 * @delimiters: The delimiters used to split the string.
 *
 * Return: The number of tokens.
 */
int count_tokens(char *line, char *delimiters)
{
int count = 0;
char *token;
char *line_copy = str_copy(line);
if (!line_copy)
return (-1);
token = strtok(line_copy, delimiters);
while (token)
{
count++;
token = strtok(NULL, delimiters);
}
free(line_copy);
return (count);
}
/**
 * free_tokens - Free an array of tokens.
 * @tokens: The array of tokens to free.
 */
void free_tokens(char **tokens)
{
int i;
if (!tokens)
return;
for (i = 0; tokens[i]; i++)
free(tokens[i]);
free(tokens);
}
/**
 * str_concat - Concatenate two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: The concatenated string, or NULL on failure.
 */
char *str_concat(const char *s1, const char *s2)
{
char *concat;
int len1, len2, i, j;
if (!s1)
s1 = "";
if (!s2)
s2 = "";
len1 = _strlen(s1);
len2 = _strlen(s2);
concat = malloc(len1 + len2 + 1);
if (!concat)
return (NULL);
for (i = 0; i < len1; i++)
concat[i] = s1[i];
for (j = 0; j < len2; j++, i++)
concat[i] = s2[j];
concat[i] = '\0';
return (concat);
}
/**
 * str_copy - Copy a string.
 * @str: The string to copy.
 *
 * Return: A pointer to the new copy of the string.
 */
char *str_copy(const char *str)
{
char *copy;
int i, len;
if (!str)
return (NULL);
len = _strlen(str);
copy = malloc(len + 1);
if (!copy)
return (NULL);
for (i = 0; i < len; i++)
copy[i] = str[i];
copy[i] = '\0';
return (copy);
}