#include "my_shell.h"

/**
 * is_chain_delimiter - test if the current character in the buffer is a chain delimiter
 * @shell_info: the shell information struct
 * @buffer: the character buffer
 * @position: address of the current position in the buffer
 *
 * Return: 1 if it's a chain delimiter, 0 otherwise
 */
int is_chain_delimiter(ShellInfo *shell_info, char *buffer, size_t *position)
{
    size_t j = *position;

    if (buffer[j] == '|' && buffer[j + 1] == '|')
    {
        buffer[j] = 0;
        j++;
        shell_info->command_buffer_type = COMMAND_OR;
    }
    else if (buffer[j] == '&' && buffer[j + 1] == '&')
    {
        buffer[j] = 0;
        j++;
        shell_info->command_buffer_type = COMMAND_AND;
    }
    else if (buffer[j] == ';') /* found end of this command */
    {
        buffer[j] = 0; /* replace semicolon with null */
        shell_info->command_buffer_type = COMMAND_CHAIN;
    }
    else
        return 0;
    *position = j;
    return 1;
}

/**
 * check_chain_condition - checks if we should continue chaining based on the last status
 * @shell_info: the shell information struct
 * @buffer: the character buffer
 * @position: address of the current position in the buffer
 * @start_position: starting position in the buffer
 * @length: length of the buffer
 *
 * Return: Void
 */
void check_chain_condition(ShellInfo *shell_info, char *buffer, size_t *position, size_t start_position, size_t length)
{
    size_t j = *position;

    if (shell_info->command_buffer_type == COMMAND_AND)
    {
        if (shell_info->status)
        {
            buffer[start_position] = 0;
            j = length;
        }
    }
    if (shell_info->command_buffer_type == COMMAND_OR)
    {
        if (!shell_info->status)
        {
            buffer[start_position] = 0;
            j = length;
        }
    }

    *position = j;
}

/**
 * replace_command_alias - replaces an alias in the tokenized string
 * @shell_info: the shell information struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_command_alias(ShellInfo *shell_info)
{
    int i;
    ListNode *node;
    char *p;

    for (i = 0; i < 10; i++)
    {
        node = find_node_starts_with(shell_info->alias_list, shell_info->arguments[0], '=');
        if (!node)
            return 0;
        free(shell_info->arguments[0]);
        p = find_character(node->value, '=');
        if (!p)
            return 0;
        p = _strdup(p + 1);
        if (!p)
            return 0;
        shell_info->arguments[0] = p;
    }
    return 1;
}

/**
 * replace_environment_variables - replaces environment variables in the tokenized string
 * @shell_info: the shell information struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_environment_variables(ShellInfo *shell_info)
{
    int i = 0;
    ListNode *node;

    for (i = 0; shell_info->arguments[i]; i++)
    {
        if (shell_info->arguments[i][0] != '$' || !shell_info->arguments[i][1])
            continue;

        if (!_strcmp(shell_info->arguments[i], "$?"))
        {
            replace_string(&(shell_info->arguments[i]),
                            _strdup(convert_number(shell_info->status, 10, 0)));
            continue;
        }
        if (!_strcmp(shell_info->arguments[i], "$$"))
        {
            replace_string(&(shell_info->arguments[i]),
                            _strdup(convert_number(getpid(), 10, 0)));
            continue;
        }
        node = find_node_starts_with(shell_info->environment_list, &shell_info->arguments[i][1], '=');
        if (node)
        {
            replace_string(&(shell_info->arguments[i]),
                            _strdup(find_character(node->value, '=') + 1));
            continue;
        }
        replace_string(&shell_info->arguments[i], _strdup(""));
    }
    return 0;
}

/**
 * replace_string - replaces a string
 * @old_string: address of the old string
 * @new_string: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old_string, char *new_string)
{
    free(*old_string);
    *old_string = new_string;
    return 1;
}
