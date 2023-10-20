#include "my_shell.h"

/**
 * my_myhistory - displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_myhistory(my_info_t *info)
{
    my_print_list(info->history);
    return (0);
}

/**
 * my_unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int my_unset_alias(my_info_t *info, char *str)
{
    char *p, c;
    int ret;

    p = my_strchr(str, '=');
    if (!p)
        return (1);
    c = *p;
    *p = 0;
    ret = my_delete_node_at_index(&(info->alias),
        my_get_node_index(info->alias, my_node_starts_with(info->alias, str, -1)));
    *p = c;
    return (ret);
}

/**
 * my_set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int my_set_alias(my_info_t *info, char *str)
{
    char *p;

    p = my_strchr(str, '=');
    if (!p)
        return (1);
    if (!*++p)
        return (my_unset_alias(info, str));

    my_unset_alias(info, str);
    return (my_add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * my_print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int my_print_alias(my_list_t *node)
{
    char *p = NULL, *a = NULL;

    if (node)
    {
        p = my_strchr(node->str, '=');
        for (a = node->str; a <= p; a++)
            my_putchar(*a);
        my_putchar('\'');
        my_puts(p + 1);
        my_puts("'\n");
        return (0);
    }
    return (1);
}

/**
 * my_myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_myalias(my_info_t *info)
{
    int i = 0;
    char *p = NULL;
    my_list_t *node = NULL;

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            my_print_alias(node);
            node = node->next;
        }
        return (0);
    }
    for (i = 1; info->argv[i]; i++)
    {
        p = my_strchr(info->argv[i], '=');
        if (p)
            my_set_alias(info, info->argv[i]);
        else
            my_print_alias(my_node_starts_with(info->alias, info->argv[i], '='));
    }

    return (0);
}
