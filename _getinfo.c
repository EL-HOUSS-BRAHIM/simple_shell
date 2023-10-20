#include "my_shell.h"

/**
 * my_clear_info - initializes my_info_t struct
 * @info: struct address
 */
void my_clear_info(my_info_t *info)
{
    info->my_arg = NULL;
    info->my_argv = NULL;
    info->my_path = NULL;
    info->my_argc = 0;
}

/**
 * my_set_info - initializes my_info_t struct
 * @info: struct address
 * @av: argument vector
 */
void my_set_info(my_info_t *info, char **av)
{
    int i = 0;

    info->my_fname = av[0];
    if (info->my_arg)
    {
        info->my_argv = my_strtow(info->my_arg, " \t");
        if (!info->my_argv)
        {

            info->my_argv = malloc(sizeof(char *) * 2);
            if (info->my_argv)
            {
                info->my_argv[0] = my_strdup(info->my_arg);
                info->my_argv[1] = NULL;
            }
        }
        for (i = 0; info->my_argv && info->my_argv[i]; i++)
            ;
        info->my_argc = i;

        my_replace_alias(info);
        my_replace_vars(info);
    }
}

/**
 * my_free_info - frees my_info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void my_free_info(my_info_t *info, int all)
{
    my_ffree(info->my_argv);
    info->my_argv = NULL;
    info->my_path = NULL;
    if (all)
    {
        if (!info->my_cmd_buf)
            free(info->my_arg);
        if (info->my_env)
            my_free_list(&(info->my_env));
        if (info->my_history)
            my_free_list(&(info->my_history));
        if (info->my_alias)
            my_free_list(&(info->my_alias));
        my_ffree(info->my_environ);
        info->my_environ = NULL;
        my_bfree((void **)info->my_cmd_buf);
        if (info->my_readfd > 2)
            close(info->my_readfd);
        my_putchar(BUF_FLUSH);
    }
}
