#include "my_shell.h"

/**
 * my_split_string - splits a string into words. Repeat delimiters are ignored
 * @input_string: the input string
 * @delimiter: the delimiter string
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **my_split_string(char *input_string, char *delimiter)
{
    int i, j, k, m, num_words = 0;
    char **strings;

    if (input_string == NULL || input_string[0] == 0)
        return NULL;
    if (!delimiter)
        delimiter = " ";
    for (i = 0; input_string[i] != '\0'; i++)
        if (!is_delimiter(input_string[i], delimiter) && (is_delimiter(input_string[i + 1], delimiter) || !input_string[i + 1]))
            num_words++;

    if (num_words == 0)
        return NULL;
    strings = malloc((1 + num_words) * sizeof(char *));
    if (!strings)
        return NULL;
    for (i = 0, j = 0; j < num_words; j++)
    {
        while (is_delimiter(input_string[i], delimiter))
            i++;
        k = 0;
        while (!is_delimiter(input_string[i + k], delimiter) && input_string[i + k])
            k++;
        strings[j] = malloc((k + 1) * sizeof(char));
        if (!strings[j])
        {
            for (k = 0; k < j; k++)
                free(strings[k]);
            free(strings);
            return NULL;
        }
        for (m = 0; m < k; m++)
            strings[j][m] = input_string[i++];
        strings[j][m] = 0;
    }
    strings[j] = NULL;
    return strings;
}

/**
 * my_split_string2 - splits a string into words
 * @input_string: the input string
 * @delimiter: the delimiter
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **my_split_string2(char *input_string, char delimiter)
{
    int i, j, k, m, num_words = 0;
    char **strings;

    if (input_string == NULL || input_string[0] == 0)
        return NULL;
    for (i = 0; input_string[i] != '\0'; i++)
        if ((input_string[i] != delimiter && input_string[i + 1] == delimiter) ||
            (input_string[i] != delimiter && !input_string[i + 1]) || input_string[i + 1] == delimiter)
            num_words++;

    if (num_words == 0)
        return NULL;
    strings = malloc((1 + num_words) * sizeof(char *));
    if (!strings)
        return NULL;
    for (i = 0, j = 0; j < num_words; j++)
    {
        while (input_string[i] == delimiter && input_string[i] != delimiter)
            i++;
        k = 0;
        while (input_string[i + k] != delimiter && input_string[i + k] && input_string[i + k] != delimiter)
            k++;
        strings[j] = malloc((k + 1) * sizeof(char));
        if (!strings[j])
        {
            for (k = 0; k < j; k++)
                free(strings[k]);
            free(strings);
            return NULL;
        }
        for (m = 0; m < k; m++)
            strings[j][m] = input_string[i++];
        strings[j][m] = 0;
    }
    strings[j] = NULL;
    return strings;
}
