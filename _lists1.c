#include "my_shell.h"

/**
 * my_list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t my_list_len(const my_list_t *h)
{
    size_t i = 0;

    while (h)
    {
        h = h->next;
        i++;
    }
    return i;
}

/**
 * my_list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **my_list_to_strings(my_list_t *head)
{
    my_list_t *node = head;
    size_t i = my_list_len(head), j;
    char **strs;
    char *str;

    if (!head || !i)
        return NULL;
    strs = malloc(sizeof(char *) * (i + 1));
    if (!strs)
        return NULL;
    for (i = 0; node; node = node->next, i++)
    {
        str = malloc(my_strlen(node->str) + 1);
        if (!str)
        {
            for (j = 0; j < i; j++)
                free(strs[j]);
            free(strs);
            return NULL;
        }

        str = my_strcpy(str, node->str);
        strs[i] = str;
    }
    strs[i] = NULL;
    return strs;
}

/**
 * my_print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t my_print_list(const my_list_t *h)
{
    size_t i = 0;

    while (h)
    {
        my_puts(my_convert_number(h->num, 10, 0));
        my_putchar(':');
        my_putchar(' ');
        my_puts(h->str ? h->str : "(nil)");
        my_puts("\n");
        h = h->next;
        i++;
    }
    return i;
}

/**
 * my_node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
my_list_t *my_node_starts_with(my_list_t *node, char *prefix, char c)
{
    char *p = NULL;

    while (node)
    {
        p = my_starts_with(node->str, prefix);
        if (p && ((c == -1) || (*p == c)))
            return node;
        node = node->next;
    }
    return NULL;
}

/**
 * my_get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t my_get_node_index(my_list_t *head, my_list_t *node)
{
    size_t i = 0;

    while (head)
    {
        if (head == node)
            return i;
        head = head->next;
        i++;
    }
    return -1;
}
