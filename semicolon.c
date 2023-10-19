#include "shell.h"
/**
 * handle_semicolon - Handle commands separated by semicolons.
 * @line: The input command line containing semicolons.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_semicolon(char *line)
{
char **commands = parse_line(line);
int i = 0;
if (commands == NULL)
{
fprintf(stderr, "handle_semicolon: memory allocation error\n");
return (-1);
}
while (commands[i])
{
if (execute(parse_line(trim_whitespace(commands[i]))))
{
fprintf(stderr, "handle_semicolon: command execution error\n");
free_args(commands);
return (-1);
}
i++;
}
free_args(commands);
return (0);
}
