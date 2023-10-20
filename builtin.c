#include "shell.h"
/**
 * new_myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int new_myexit(ino_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = new_erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			new_print_error(info, "Illegal number: ");
			new_eputs(info->argv[1]);
			new_eputchar('\n');
			return (1);
		}
		info->err_num = new_erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * new_mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int new_mycd(ino_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		new_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = new_getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = new_getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (new_strcmp(info->argv[1], "-") == 0)
	{
		if (!new_getenv(info, "OLDPWD="))
		{
			new_puts(s);
			_new_putchar('\n');
			return (1);
		}
		new_puts(new_getenv(info, "OLDPWD=")), _new_putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = new_getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		new_print_error(info, "can't cd to ");
		new_eputs(info->argv[1]), new_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", new_getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * new_myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int new_myhelp(ino_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	new_puts("help call works. Function not yet implemented \n");
	if (0)
		new_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
