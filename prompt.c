#include "shell.h"
/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
char *prompt = "$ ";
write(STDOUT_FILENO, prompt, _strlen(prompt));
}
/**
 * read_input - Read a line of input from the user
 *
 * Return: A pointer to the input line (string), or NULL on failure or EOF
 */
char *read_input(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
nread = getline(&line, &len, stdin);
if (nread == -1)
{
free(line);
if (feof(stdin))
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
return (NULL); /* EOF (Ctrl-D) */
}
perror("read_input");
return (NULL); /* Error */
}
if (nread > 0 && line[nread - 1] == '\n')
line[nread - 1] = '\0'; /* Remove newline character */
return (line);
}