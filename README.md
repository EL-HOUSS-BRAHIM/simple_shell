# Simple Unix Shell

## Table of Contents
- [Project Description](#project-description)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Builtin Commands](#builtin-commands)
- [Additional Features](#additional-features)
- [Contributing](#contributing)
- [Authors](#authors)
- [License](#license)

## Project Description

The Simple Unix Shell is a command-line interpreter that allows users to execute basic Unix commands. This project is part of the curriculum at ALX Software Engineering and aims to provide a fundamental understanding of system calls, process management, and Unix command execution.

## Getting Started

### Prerequisites

Before you begin, ensure you have the following prerequisites:

- A Unix-based operating system (e.g., Linux)
- GCC compiler
- A code editor (e.g., Vim, Emacs)

### Compilation

You can compile the shell using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

## Usage

To run the Simple Unix Shell, execute the following command in your terminal:

```bash
./simple_shell
```

Once the shell is running, you can enter Unix commands and execute them.

## Project Structure

The project is organized into several source files, each serving a specific purpose:

- `main.c`: Entry point for the shell.
- `helpers.c`: Utility functions for error handling and string manipulation.
- `builtins.c`: Implementations of builtin commands like `exit` and `env`.
- `execution.c`: Execution of external commands and handling PATH.
- `tokenization.c`: Tokenizing user input.
- `path_handling.c`: Parsing and searching directories in PATH.
- `error_handling.c`: Error handling and error message display.
- `memory.c`: Memory allocation and deallocation functions.
- `variables.c`: Managing special variables like `$?` and `$$`.

## Builtin Commands

The shell supports the following builtin commands:

- `exit`: Exit the shell.
- `env`: Print the current environment variables.

## Additional Features

This shell can be extended with optional features such as:

- `alias`: Managing aliases for commands.
- `comments`: Handling comments in user input.
- `logical_operators`: Supporting logical operators (`&&` and `||`).
- `command_separator`: Handling command separator (`;`).
- `file_input`: Reading and executing commands from a file.

## Contributing

Contributions to this project are welcome. You can contribute by:

1. Forking the repository.
2. Creating a new branch for your feature or bug fix.
3. Making your changes and testing them.
4. Creating a pull request with a clear description of your changes.

## Authors

- [BRAHIM EL HOUSS](https://github.com/EL-HOUSS-BRAHIM/simple_shell.git) - Owner
- [AYOUB KIAL] - Owner

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
