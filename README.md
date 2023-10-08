```markdown
# Simple Shell Program

This is a simple shell program written in C. It provides basic shell functionality, including executing commands, handling built-in commands, and managing environment variables.

## Features

- Command execution: The shell can execute external commands entered by the user.
- Built-in commands: It supports several built-in commands such as `exit`, `env`, `setenv`, `unsetenv`, and `cd`.
- Environment variable management: You can get, set, and unset environment variables.
- Customizable prompt: The shell displays a custom prompt, which you can modify as needed.

## Prerequisites

Before running the shell program, ensure that you have the following:

- A C compiler (e.g., GCC)
- Standard C libraries
- A Unix-like operating system (Linux, macOS, or similar)

## How to Compile

Compile the shell program using the following command:

```shell
gcc -o myshell main.c utility_funcs.c str_funcs.c prompt.c execute.c helper.c environ.c getline.c builtins.c -lm


## How to Run

To run the shell program, use the following command:

```shell
./myshell


## Usage

Once the shell is running, you can enter commands just like you would in a standard shell. You can also use the built-in commands.

### Examples

- Execute an external command:

  ```shell
  ls -l


- Use built-in commands:

  ```shell
  exit
  env
  setenv MY_VARIABLE my_value
  unsetenv MY_VARIABLE
  cd /path/to/directory


## Author

[Your Name]

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
```
