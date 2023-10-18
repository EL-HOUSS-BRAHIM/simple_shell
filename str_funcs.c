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
if (line == NULL)
return (NULL);
size_t token_size = TOKEN_SIZE;
char **tokens = (char **)malloc(sizeof(char *) * token_size);
if (tokens == NULL)
return (NULL);
size_t token_count = 0;
char *token = strtok(line, delimiters);
while (token != NULL)
{
if (token_count >= token_size - 1)
{
token_size *= 2;
tokens = (char **)realloc(tokens, sizeof(char *) * token_size);
if (tokens == NULL)
{
handle_allocation_failure(tokens, token_count);
return (NULL);
}
}
tokens[token_count] = strdup(token);
if (tokens[token_count] == NULL)
{
handle_allocation_failure(tokens, token_count);
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
 * replace_variables - Replaces environment variables in a string...
 * @line: The input string
 * @env: The environment variables as an array of strings
 *
 * Return: A new string with variables replaced, or NULL on failure
 */
char *replace_variables(char *line, char **env)
{
char *result = NULL;
char *start = line;
while (*start)
{
if (*start == '$' && start[1])
{
char *end = start + 1;
while (*end && (isalnum(*end) || *end == '_'))
end++;
if (end - start > 1)
{
char *var_name = strndup(start + 1, end - start - 1);
if (var_name)
{
char *var_value = get_env_value(env, var_name);
result = _strcat(result, var_value ? var_value : "$");
free(var_name);
}
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
return (result);
}
