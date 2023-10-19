#include "shell.h"
/**
 * handle_logical_operators - Handle commands with logical operators.
 * @line: The input command line containing logical operators.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_logical_operators(char *line)
{
char **commands;
int i = 0;
commands = parse_line(line);
if (commands == NULL)
{
fprintf(stderr, "handle_logical_operators: memory allocation error\n");
return -1;
}
while (commands[i])
{
if (strstr(commands[i], "&&"))
{
if (execute(parse_line(trim_whitespace(commands[i]))))
{
fprintf(stderr, "handle_logical_operators: command execution error\n");
free_args(commands);
return -1;
}
if (execute(parse_line(trim_whitespace(commands[i + 1])))
{
fprintf(stderr, "handle_logical_operators: command execution error\n");
free_args(commands);
return -1;
}
i++;
}
else if (strstr(commands[i], "||"))
{
if (!execute(parse_line(trim_whitespace(commands[i]))))
{
fprintf(stderr, "handle_logical_operators: command execution error\n");
free_args(commands);
return -1;
}
if (execute(parse_line(trim_whitespace(commands[i + 1])))
{
fprintf(stderr, "handle_logical_operators: command execution error\n");
free_args(commands);
return -1;
}
i++;
}
else
{
if (execute(parse_line(trim_whitespace(commands[i])))
{
fprintf(stderr, "handle_logical_operators: command execution error\n");
free_args(commands);
return -1;
}
}
i++;
}
free_args(commands);
return 0;
}