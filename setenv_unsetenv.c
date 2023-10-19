#include "shell.h"

/**
 * setenv - Set an environment variable or update its value.
 * @info: Structure containing potential arguments.
 * @var: The name of the environment variable.
 * @value: The value to set or update.
 * @overwrite: Flag to indicate whether to overwrite the variable if it exists.
 * Return: 0 on success, -1 on failure.
 */
int _setenv(info_t *info, char *var, char *value, int overwrite)
{
    char *buf = NULL;
    list_t *node;
    char *p;

    if (!var || !value) {
        return (-1);
    }

    buf = malloc(_strlen(var) + _strlen(value) + 2);
    if (!buf) {
        return (-1);
    }
    _strcpy(buf, var);
    _strcat(buf, "=");
    _strcat(buf, value);
    node = info->env;

    while (node) {
        p = starts_with(node->str, var);
        if (p && *p == '=') {
            if (overwrite) {
                free(node->str);
                node->str = buf;
                return (0);
            } else {
                free(buf);
                return (0);
            }
        }
        node = node->next;
    }

    add_node_end(&(info->env), buf, 0);
    free(buf);
    return (0);
}

/**
 * unsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments.
 * @var: The name of the environment variable to unset.
 * Return: 1 on delete, 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
    list_t *node = info->env;
    size_t i = 0;
    char *p;

    if (!node || !var) {
        return (0);
    }

    while (node) {
        p = starts_with(node->str, var);
        if (p && *p == '=') {
            info->env_changed = delete_node_at_index(&(info->env), i);
            i = 0;
            node = info->env;
            continue;
        }
        node = node->next;
        i++;
    }
    return (info->env_changed);
}
