#include "shell.h"
/**
 * get_env_value - Get the value of an environment variable
 * @env: The array of environment variables
 * @name: The name of the environment variable to search for
 *
 * Return: A pointer to the value of the environment variable, or NULL if not..
 */
char *get_env_value(char **env, const char *name)
{
int i = 0;
size_t name_len = _strlen(name);
while (env[i] != NULL)
{
if (_strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
return (env[i] + name_len + 1);
i++;
}
return (NULL);
}
/**
 * set_env_value - Set the value of an environment variable
 * @env: A pointer to the array of environment variables
 * @name: The name of the environment variable to set
 * @value: The value to set for the environment variable
 *
 * Return: 0 on success, -1 on failure
 */
void set_env_value(char ***env, const char *name, const char *value)
{
int i = 0;
int j;
size_t name_len = _strlen(name);
char *new_entry;
char **new_env;
while ((*env)[i] != NULL)
{
if (_strncmp((*env)[i], name, name_len) == 0 && (*env)[i][name_len] == '=')
{
free((*env)[i]);
(*env)[i] = _strcat(_strcat(_strdup(name), "="), value);
return;
}
i++;
}
new_entry = _strcat(_strcat(_strdup(name), "="), value);
new_env = malloc((i + 2) * sizeof(char *));
if (new_env == NULL)
{
perror("set_env_value");
exit(EXIT_FAILURE);
}
for (j = 0; j < i; j++)
new_env[j] = (*env)[j];
new_env[i] = new_entry;
new_env[i + 1] = NULL;
free(*env);
*env = new_env;
}
/**
 * unset_env_variable - Unset an environment variable
 * @env: A pointer to the array of environment variables
 * @name: The name of the environment variable to unset
 */
void unset_env_variable(char ***env, const char *name)
{
int i = 0;
size_t name_len = _strlen(name);
while ((*env)[i] != NULL)
{
if (_strncmp((*env)[i], name, name_len) == 0 && (*env)[i][name_len] == '=')
{
free((*env)[i]);
while ((*env)[i + 1] != NULL)
{
(*env)[i] = (*env)[i + 1];
i++;
}
(*env)[i] = NULL;
return;
}
i++;
}
}
