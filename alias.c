#include "shell.h"
/**
 * add_alias - Add an alias to the alias list.
 * @alias_list: A pointer to the alias list.
 * @name: The name of the alias.
 * @value: The value of the alias.
 */
void add_alias(Alias **alias_list, char *name, char *value)
{
Alias *new_alias, *temp;
new_alias = malloc(sizeof(Alias));
if (!new_alias)
{
fprintf(stderr, "add_alias: memory allocation error\n");
return;
}
new_alias->name = strdup(name);
if (!new_alias->name)
{
fprintf(stderr, "add_alias: memory allocation error\n");
free(new_alias);
return;
}
new_alias->value = strdup(value);
if (!new_alias->value)
{
fprintf(stderr, "add_alias: memory allocation error\n");
free(new_alias->name);
free(new_alias);
return;
}
new_alias->next = NULL;
if (*alias_list == NULL)
{
*alias_list = new_alias;
return;
}
temp = *alias_list;
while (temp->next)
temp = temp->next;
temp->next = new_alias;
}
/**
 * print_aliases - Print the list of aliases.
 * @alias_list: The list of aliases.
 */
void print_aliases(Alias *alias_list)
{
Alias *temp = alias_list;
while (temp)
{
printf("%s='%s'\n", temp->name, temp->value);
temp = temp->next;
}
}
