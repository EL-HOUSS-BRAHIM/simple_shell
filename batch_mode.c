#include "shell.h"
/**
 * batch_mode - Execute commands from a file in batch mode.
 * @filename: The name of the file containing commands.
 * Return: 0 on success, -1 on failure.
 */
int batch_mode(char *filename)
{
FILE *file;
char *line = NULL;
size_t len = 0;
ssize_t read;
int status = 0;
file = fopen(filename, "r");
if (!file)
{
perror("batch_mode");
return -1;
}
while ((read = getline(&line, &len, file)) != -1)
{
char **args;
int result;
if (read > 0 && line[read - 1] == '\n')
line[read - 1] = '\0';
args = parse_line(line);
if (args)
{
result = execute(args);
if (result != 0)
status = -1;
free_args(args);
}
}
free(line);
fclose(file);
return status;
}