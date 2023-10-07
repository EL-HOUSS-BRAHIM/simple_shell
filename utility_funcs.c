#include "shell.h"

/**
 * _strlen - Calculate the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
    int len = 0;

    if (s == NULL)
        return (0);

    while (s[len] != '\0')
        len++;

    return (len);
}

/**
 * _strcmp - Compare two strings
 * @s1: The first input string
 * @s2: The second input string
 *
 * Return: 0 if the strings are equal, a negative value if s1 < s2,
 * and a positive value if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (-1);

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;

    return (s1[i] - s2[i]);
}
/**
 * _atoi - Convert a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer value of the string.
 */
int _atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }

    for (; str[i] != '\0'; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
        }
        else
        {
            break;
        }
    }

    return result * sign;
}
/**
 * _puts - Print a string to stdout.
 * @str: The string to print.
 */
void _puts(const char *str)
{
    while (*str)
    {
        _putchar(*str);
        str++;
    }
}
/**
 * _putchar - Write a character to stdout.
 * @c: The character to write.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}
/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the variable to retrieve.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
    int i;
    size_t name_len = _strlen(name);

    for (i = 0; (env)[i]; i++)
    {
        if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            return environ[i] + name_len + 1;
        }
    }
    return NULL;
}
/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to append to dest.
 *
 * Return: The concatenated string.
 */
char *_strcat(char *dest, const char *src)
{
    int dest_len = _strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';

    return dest;
}
/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: The duplicated string.
 */
char *_strdup(const char *str)
{
    int len = _strlen(str);
    char *dup = malloc(len + 1);

    if (dup == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    _strcpy(dup, str);

    return dup;
}
/**
 * _strncmp - Compare two strings up to n characters.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal, an integer less than 0 if s1 is less than s2,
 *         or an integer greater than 0 if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    for (i = 0; i < n && (s1[i] != '\0' || s2[i] != '\0'); i++)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }

    return 0;
}
/**
 * _realloc - Reallocate memory.
 * @ptr: Pointer to the previously allocated memory.
 * @old_size: Old size of the memory.
 * @new_size: New size of the memory.
 *
 * Return: Pointer to the reallocated memory.
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;

    if (ptr == NULL)
    {
        new_ptr = malloc(new_size);
        if (new_ptr == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        return new_ptr;
    }

    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (old_size < new_size)
    {
        _memcpy(new_ptr, ptr, old_size);
    }
    else
    {
        _memcpy(new_ptr, ptr, new_size);
    }

    free(ptr);
    return new_ptr;
}
/**
 * _strncat - Concatenate two strings up to n characters.
 * @dest: The destination string.
 * @src: The source string to append to dest.
 * @n: The maximum number of characters to append.
 *
 * Return: The concatenated string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
    size_t dest_len = _strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';

    return dest;
}
/**
 * _strcpy - Copy a string.
 * @dest: The destination buffer.
 * @src: The source string to copy.
 *
 * Return: The destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}
/**
 * _memcpy - Copy memory area.
 * @dest: Destination memory area.
 * @src: Source memory area.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to the destination memory area.
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    while (n--)
    {
        *d++ = *s++;
    }

    return dest;
}
