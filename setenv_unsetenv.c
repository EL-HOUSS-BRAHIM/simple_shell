#include "shell.h"

int setenv(const char *name, const char *value, int overwrite) {
char* existing_value = getenv(name);
char env_var[MAX_ENV_NAME_LENGTH];
if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
fprintf(stderr, "setenv: Invalid environment variable name\n");
return -1;
}
if (*value == '\0') {
fprintf(stderr, "setenv: Value cannot be NULL\n");
return -1;
}
if (existing_value != NULL && overwrite == 0) {
return 0;
}
snprintf(env_var, MAX_ENV_NAME_LENGTH, "%s=%s", name, value);
if (existing_value) {
if (unsetenv(name) != 0) {
fprintf(stderr, "setenv: Failed to unset existing environment variable\n");
return -1;
}
}
if (putenv(env_var) != 0) {
fprintf(stderr, "setenv: Failed to set environment variable\n");
return -1;
}
return 0;
}
int unsetenv(const char *name) {
char env_var[MAX_ENV_NAME_LENGTH];
if (*name == '\0' || strchr(name, '=') != NULL) {
fprintf(stderr, "unsetenv: Invalid environment variable name\n");
return -1;
}
if (getenv(name) == NULL) {
return 0;
}
snprintf(env_var, MAX_ENV_NAME_LENGTH, "%s=", name);
if (putenv(env_var) != 0) {
fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
return -1;
}
return 0;
}
