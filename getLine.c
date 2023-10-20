#include "my_shell.h"

/**
 * buffer_chained_commands - buffers chained commands
 * @shell_info: parameter structure
 * @buffer: address of buffer
 * @length: address of length variable
 *
 * Return: bytes read
 */
ssize_t buffer_chained_commands(ShellInfo *shell_info, char **buffer, size_t *length)
{
    ssize_t bytes_read = 0;
    size_t length_p = 0;

    if (!*length) /* If nothing left in the buffer, fill it */
    {
        free(*buffer);
        *buffer = NULL;
        signal(SIGINT, handle_sigint);

        bytes_read = getline(buffer, &length_p, stdin);

        if (bytes_read > 0)
        {
            if ((*buffer)[bytes_read - 1] == '\n')
            {
                (*buffer)[bytes_read - 1] = '\0'; /* Remove trailing newline */
                bytes_read--;
            }

            shell_info->linecount_flag = 1;
            remove_comments(*buffer);
            build_history_list(shell_info, *buffer, shell_info->histcount++);

            *length = bytes_read;
            shell_info->cmd_buf = buffer;
        }
    }

    return bytes_read;
}

/**
 * get_user_input - gets a line without the newline character
 * @shell_info: parameter structure
 *
 * Return: bytes read
 */
ssize_t get_user_input(ShellInfo *shell_info)
{
    static char *buffer; /* The ';' command chain buffer */
    static size_t i, j, length;
    ssize_t bytes_read = 0;
    char **buffer_p = &(shell_info->arguments), *p;

    _putchar(BUF_FLUSH);
    bytes_read = buffer_chained_commands(shell_info, &buffer, &length);

    if (bytes_read == -1) /* EOF */
        return -1;

    if (length) /* We have commands left in the chain buffer */
    {
        j = i; /* Initialize a new iterator to the current buffer position */
        p = buffer + i; /* Get a pointer for return */

        check_command_chain(shell_info, buffer, &j, i, length);

        while (j < length) /* Iterate to semicolon or end */
        {
            if (is_command_chain(shell_info, buffer, &j))
                break;
            j++;
        }

        i = j + 1; /* Increment past nulled ';' */
        if (i >= length) /* Reached the end of the buffer? */
        {
            i = length = 0; /* Reset position and length */
            shell_info->cmd_buf_type = CMD_NORMAL;
        }

        *buffer_p = p; /* Pass back a pointer to the current command position */
        return _strlen(p); /* Return the length of the current command */
    }

    *buffer_p = buffer; /* Not a chain, pass back the buffer from getline() */
    return bytes_read; /* Return the length of the buffer from getline() */
}

/**
 * read_buffer - reads a buffer
 * @shell_info: parameter structure
 * @buffer: buffer
 * @i: size
 *
 * Return: bytes read
 */
ssize_t read_buffer(ShellInfo *shell_info, char *buffer, size_t *i)
{
    ssize_t bytes_read = 0;

    if (*i)
        return 0;

    bytes_read = read(shell_info->read_fd, buffer, READ_BUFFER_SIZE);

    if (bytes_read >= 0)
        *i = bytes_read;

    return bytes_read;
}

/**
 * _my_getline - gets the next line of input from STDIN
 * @shell_info: parameter structure
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _my_getline(ShellInfo *shell_info, char **ptr, size_t *length)
{
    static char buffer[READ_BUFFER_SIZE];
    static size_t i, len;
    size_t k;
    ssize_t r = 0, s = 0;
    char *p = NULL, *new_p = NULL, *c;

    p = *ptr;
    if (p && length)
        s = *length;

    if (i == len)
    {
        i = len = 0;
    }

    r = read_buffer(shell_info, buffer, &len);
    if (r == -1 || (r == 0 && len == 0))
        return -1;

    c = _strchr(buffer + i, '\n');
    k = c ? 1 + (unsigned int)(c - buffer) : len;
    new_p = _realloc(p, s, s ? s + k : k + 1);

    if (!new_p) /* MALLOC FAILURE! */
        return (p ? free(p), -1 : -1);

    if (s)
        _strncat(new_p, buffer + i, k - i);
    else
        _strncpy(new_p, buffer + i, k - i + 1);

    s += k - i;
    i = k;
    p = new_p;

    if (length)
        *length = s;
    *ptr = p;
    return s;
}

/**
 * handle_sigint - blocks Ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void handle_sigint(__attribute__((unused)) int sig_num)
{
    _puts("\n");
    _puts("$ ");
    _putchar(BUF_FLUSH);
}
