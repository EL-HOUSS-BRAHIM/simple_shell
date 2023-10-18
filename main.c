#include "shell.h"
/**
 * main - Entry point of the simple shell program
 * @argc: The number of arguments
 * @argv: The arguments array
 * @env: The environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char *argv[], char **env)
{
(void)argc;
(void)argv;
start_shell(env);
return (0);
}
/**
 * start_shell - Starts the simple shell
 * @env: The environment variables
 */
void start_shell(char **env __attribute__((unused)))
{
char *input_line;
char **args;
int status;
do {
display_prompt();
input_line = read_input();
if (!input_line)
break;
args = tokenize(input_line, " \t\n\r");
if (!args || !args[0]) {
free(input_line);
continue;
}
status = execute_command(args, &env);
free(input_line);
free(args);
} while (status != 0);
}