#include "shell.h"
/**
 * add_variable - Add a variable to the variable list.
 * @variable_list: A pointer to the variable list.
 * @name: The name of the variable.
 * @value: The value of the variable.
 */
void add_variable(Variable **variable_list, char *name, char *value)
{
Variable *new_variable, *temp;
new_variable = malloc(sizeof(Variable));
if (!new_variable)
{
fprintf(stderr, "add_variable: memory allocation error\n");
return;
}
new_variable->name = strdup(name);
if (!new_variable->name)
{
fprintf(stderr, "add_variable: memory allocation error\n");
free(new_variable);
return;
}
new_variable->value = strdup(value);
if (!new_variable->value)
{
fprintf(stderr, "add_variable: memory allocation error\n");
free(new_variable->name);
free(new_variable);
return;
}
new_variable->next = NULL;
if (*variable_list == NULL)
{
*variable_list = new_variable;
return;
}
temp = *variable_list;
while (temp->next)
temp = temp->next;
temp->next = new_variable;
}
/**
 * expand_variables - Expand variables in a line.
 * @line: The line containing variables to expand.
 * @variable_list: The list of variables.
 * Return: The line with expanded variables.
 */
char *expand_variables(char *line, Variable *variable_list)
{
char *result = strdup(line);
char *token, *saveptr;
Variable *temp;
if (!result)
{
fprintf(stderr, "expand_variables: memory allocation error\n");
return line;
}
token = strtok_r(result, " \t", &saveptr);
while (token)
{
temp = variable_list;
while (temp)
{
if (strcmp(token, temp->name) == 0)
{
free(result);
result = strdup(temp->value);
if (!result)
{
fprintf(stderr, "expand_variables: memory allocation error\n");
return line;
}
break;
}
temp = temp->next;
}
token = strtok_r(NULL, " \t", &saveptr);
}
return result;
}
/**
 * print_variables - Print the list of variables.
 * @variable_list: The list of variables.
 */
void print_variables(Variable *variable_list)
{
Variable *temp = variable_list;
while (temp)
{
printf("%s='%s'\n", temp->name, temp->value);
temp = temp->next;
}
}