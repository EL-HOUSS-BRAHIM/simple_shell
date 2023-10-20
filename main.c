#include "my_shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
    ShellInfo shell_info[] = { SHELL_INFO_INIT };
    int file_descriptor = 2;

    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (file_descriptor)
        : "r" (file_descriptor));

    if (argc == 2)
    {
        file_descriptor = open(argv[1], O_RDONLY);
        if (file_descriptor == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(argv[0]);
                _eputs(": 0: Can't open ");
                _eputs(argv[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return EXIT_FAILURE;
        }
        shell_info->read_fd = file_descriptor;
    }

    populate_environment_list(shell_info);
    read_shell_history(shell_info);
    my_shell(shell_info, argv);
    
    return EXIT_SUCCESS;
}
