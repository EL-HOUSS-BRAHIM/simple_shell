#include "shell.h"
/**
 * new_clear_info - initializes ino_t struct
 * @info: struct address
 */
void new_clear_info(ino_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * new_set_info - initializes ino_t struct
 * @info: struct address
 * @av: argument vector
 */
void new_set_info(ino_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = new_strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = new_strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		new_replace_alias(info);
		new_replace_vars(info);
	}
}

/**
 * new_free_info - frees ino_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void new_free_info(ino_t *info, int all)
{
	new_ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			new_free_list(&(info->env));
		if (info->history)
			new_free_list(&(info->history));
		if (info->alias)
			new_free_list(&(info->alias));
		new_ffree(info->environ);
			info->environ = NULL;
		new_bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_new_putchar(NEW_BUF_FLUSH);
	}
}
