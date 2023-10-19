#include "shell.h"
/**
 * tokenize - Tokenizes a string based on delimiters
 * @line: The input string to tokenize
 * @delimiters: A string containing the delimiter characters
 *
 * Return: An array of tokens (strings)
 */
char **tokenize(char *line, char *delimiters)
{
char **tokens = NULL;
char *token = NULL;
size_t token_count = 0;
size_t token_size = TOKEN_SIZE;
size_t i;
if (line == NULL)
return (NULL);
tokens = (char **)malloc(sizeof(char *) * token_size);
if (tokens == NULL)
return (NULL);
token = strtok(line, delimiters);
while (token != NULL)
{
if (token_count >= token_size - 1)
{
token_size *= 2;
tokens = (char **)realloc(tokens, sizeof(char *) * token_size);
if (tokens == NULL)
{
/* Handle allocation failure */
for (i = 0; i < token_count; i++)
free(tokens[i]);
free(tokens);
return (NULL);
}
}
tokens[token_count] = strdup(token);
if (tokens[token_count] == NULL)
{
/* Handle allocation failure */
for (i = 0; i < token_count; i++)
free(tokens[i]);
free(tokens);
return (NULL);
}
token_count++;
token = strtok(NULL, delimiters);
}
tokens[token_count] = NULL;
return (tokens);
}
/**
 * trim_whitespace - Removes leading and trailing whitespace from a string
 * @str: The input string
 *
 * Return: A new string with leading/trailing whitespace removed
 */
char *trim_whitespace(char *str)
{
size_t len = 0;
char *trimmed = NULL;
size_t start = 0;
size_t end = 0;
if (str == NULL)
return (NULL);
len = strlen(str);
while (isspace(str[start]))
start++;
if (start == len)
return (strdup(""));
end = len - 1;
while (isspace(str[end]))
end--;
trimmed = strndup(str + start, end - start + 1);
if (trimmed == NULL)
return (NULL);
return (trimmed);
}
/**
 * replace_variables - Replaces environment variables in a string..
 * @line: The input string
 * @env: The environment variables as an array of strings
 *
 * Return: A new string with variables replaced, or NULL on failure
 */
char *replace_variables(char *line, char **env)
{
char *result = NULL;
char *start = line;
char *end = NULL;
char *var_name = NULL;
char *var_value = NULL;
size_t len = 0;
while (*start)
{
if (*start == '$' && *(start + 1))
{
end = start + 1;
while (*end && (isalnum(*end) || *end == '_'))
{
end++;
}
len = end - start - 1;
if (len > 0)
{
var_name = strndup(start + 1, len);
var_value = get_env_value(env, var_name);
free(var_name);
}
if (var_value)
{
result = _strcat(result, var_value);
}
else
{
result = _strncat(result, start, 1);
}
start = end;
}
else
{
result = _strncat(result, start, 1);
start++;
}
}
return result;
}
