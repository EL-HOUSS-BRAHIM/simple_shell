#include "shell.h"
/**
 * main - Entry point for the simple shell.
 * @ac: The number of command-line arguments.
 * @av: An array containing the command-line arguments.
 * @env: The array of environment variables.
 * Return: The shell's exit status.
 */
int main(int ac, char *av[], char *env[])
{
UNUSED(ac);
UNUSED(av);
UNUSED(env);
char *line;
char **args;
int status;
do {
printf("($) ");
line = read_line();
if (line == NULL)
{
printf("\n");
break;
}
args = parse_line(line);
if (args == NULL)
{
free(line);
continue;
}
status = execute(args);
free_args(args);
free(line);
} while (status != -1);
return (0);
}
