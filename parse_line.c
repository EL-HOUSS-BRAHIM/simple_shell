#include "shell.h"
/**
 * parse_line - Tokenize a line of input into an array of strings.
 * @line: The input line to be tokenized.
 *
 * Return: An array of strings (tokens).
 */
char **parse_line(char *line)
{
char **tokens;
char *token;
int token_count = 0;
int i = 0;
if (line == NULL)
return (NULL);
token_count = count_tokens(line);
if (token_count == 0)
return (NULL);
tokens = malloc((token_count + 1) * sizeof(char *));
if (tokens == NULL)
return (NULL);
token = _strtok(line, " \t\n");
while (token != NULL)
{
tokens[i] = token;
token = _strtok(NULL, " \t\n");
i++;
}
tokens[i] = NULL;
return (tokens);
}