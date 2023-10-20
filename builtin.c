#include "my_shell.h"

/**
 * exit_shell - exits the shell
 * @shell_info: Structure containing potential arguments. Used to maintain
 *          a consistent function prototype.
 *  Return: exits with a given exit status
 *         (0) if shell_info->arguments[0] != "exit"
 */
int exit_shell(ShellInfo *shell_info)
{
    int exit_status;

    if (shell_info->arguments[1])  /* If there is an exit argument */
    {
        exit_status = parse_integer(shell_info->arguments[1]);
        if (exit_status == -1)
        {
            shell_info->status = 2;
            print_error(shell_info, "Illegal number: ");
            print_string(shell_info->arguments[1]);
            print_character('\n');
            return 1;
        }
        shell_info->err_number = exit_status;
        return -2;
    }
    shell_info->err_number = -1;
    return -2;
}

/**
 * change_directory - changes the current directory of the process
 * @shell_info: Structure containing potential arguments. Used to maintain
 *          a consistent function prototype.
 *  Return: Always 0
 */
int change_directory(ShellInfo *shell_info)
{
    char *cwd_buffer, *new_dir;
    int chdir_result;

    cwd_buffer = getcwd(buffer, 1024);
    if (!cwd_buffer)
        print_string("TODO: >>getcwd failure message here<<\n");

    if (!shell_info->arguments[1])
    {
        new_dir = get_environment_variable(shell_info, "HOME=");
        if (!new_dir)
            chdir_result = chdir((new_dir = get_environment_variable(shell_info, "PWD=")) ? new_dir : "/");
        else
            chdir_result = chdir(new_dir);
    }
    else if (compare_strings(shell_info->arguments[1], "-") == 0)
    {
        if (!get_environment_variable(shell_info, "OLDPWD="))
        {
            print_string(cwd_buffer);
            print_character('\n');
            return 1;
        }
        print_string(get_environment_variable(shell_info, "OLDPWD="));
        print_character('\n');
        chdir_result = chdir((new_dir = get_environment_variable(shell_info, "OLDPWD=")) ? new_dir : "/");
    }
    else
        chdir_result = chdir(shell_info->arguments[1]);

    if (chdir_result == -1)
    {
        print_error(shell_info, "can't cd to ");
        print_string(shell_info->arguments[1]);
        print_character('\n');
    }
    else
    {
        set_environment_variable(shell_info, "OLDPWD", get_environment_variable(shell_info, "PWD="));
        set_environment_variable(shell_info, "PWD", getcwd(buffer, 1024));
    }
    return 0;
}

/**
 * display_help - displays help information
 * @shell_info: Structure containing potential arguments. Used to maintain
 *          a consistent function prototype.
 *  Return: Always 0
 */
int display_help(ShellInfo *shell_info)
{
    char **arg_array;

    arg_array = shell_info->arguments;
    print_string("Help call works. Function not yet implemented \n");
    if (0)
        print_string(*arg_array); /* Temporary unused variable workaround */
    return 0;
}
