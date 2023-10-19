#include "shell.h"
/**
 * handle_logical_operators - Handle commands with logical operators.
 * @line: The input command line containing logical operators.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_logical_operators(char *line)
{
char **commands = parse_line(line);
int i = 0;
int status = 0;
if (commands == NULL)
{
fprintf(stderr, "handle_logical_operators: memory allocation error\n");
return -1;
}
while (commands[i])
{
if (status == 0 || (status == 1 && strstr(commands[i], "||")))
{
if (execute(parse_line(trim_whitespace(commands[i]))))
{
fprintf(stderr, "handle_logical_operators: command execution error\n");
free_args(commands);
return -1;
}
status = 0;
}
else if (status == 1 && strstr(commands[i], "&&"))
status = 0;
else
{
fprintf(stderr, "handle_logical_operators: invalid operator usage\n");
free_args(commands);
return -1;
}
i++;
}
free_args(commands);
return 0;
}
