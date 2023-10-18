#include "shell.h"
/**
 * _strncmp - Compare two strings up to n characters.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal, an integer less than 0 if s1 is less than s2,
 * or an integer greater than 0 if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;
for (i = 0; i < n && (s1[i] != '\0' || s2[i] != '\0'); i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}
return (0);
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
return (new_ptr);
}
if (new_size == 0)
{
free(ptr);
return (NULL);
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
return (new_ptr);
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
return (dest);
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
return (dest);
}