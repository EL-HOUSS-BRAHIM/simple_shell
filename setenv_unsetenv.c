#include "shell.h"
/**
 * setenv - Set an environment variable or update its value.
 * @name: The name of the environment variable.
 * @value: The value to set or update.
 * @overwrite: Flag to indicate whether to overwrite the variable if it exists.
 * Return: 0 on success, -1 on failure.
 */
int setenv(const char *name, const char *value, int overwrite)
{
char *env_var;
if (name == NULL || name[0] == '\0' || (value == NULL && overwrite))
{
fprintf(stderr, "setenv: invalid arguments\n");
return (-1);
}
if (overwrite || getenv(name) == NULL)
{
if (putenv(strdup(name)) != 0)
{
perror("setenv");
return (-1);
}
}
env_var = malloc(strlen(name) + strlen(value) + 2);
if (!env_var)
{
perror("setenv");
return (-1);
}
strcpy(env_var, name);
strcat(env_var, "=");
strcat(env_var, value);
if (putenv(env_var) != 0)
{
perror("setenv");
free(env_var);
return (-1);
}
return (0);
}
/**
 * unsetenv - Unset an environment variable.
 * @name: The name of the environment variable to unset.
 * Return: 0 on success, -1 on failure.
 */
int unsetenv(const char *name)
{
if (!name || name[0] == '\0' || getenv(name) == NULL)
{
fprintf(stderr, "unsetenv: invalid arguments\n");
return (-1);
}
if (getenv(name) != NULL)
{
if (putenv(strdup(name)) != 0)
{
perror("unsetenv");
return (-1);
}
}
return (0);
}
