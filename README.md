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
- ´project-name´/
- │
- ├── ´errors.c´
- │   - Source code for error handling functions.
- │   - Contains functions for printing error messages.
- │
- ├── ´errors1.c´
- │   - Source code for additional error-related functions.
- │   - Includes functions for string to integer conversion and error message printing.
- │
- ├── ´exits.c´
- │   - Source code for functions related to string manipulation.
- │   - Contains string copying, concatenation, and character searching functions.
- │
- ├── ´getenv.c´
- │   - Source code for handling environment variables.
- │   - Includes functions for retrieving, setting, and unsetting environment variables.
- │
- ├── ´getinfo.c´
- │   - Source code for managing program and command information.
- │   - Contains functions for initializing, clearing, and freeing information structures.
- │
- ├── ´history.c´
- │   - Source code for managing command history.
- │   - Includes functions for reading and writing command history to a file.
- │
- ├── ´lists.c´
- │   - Source code for handling linked lists.
- │   - Contains functions for creating, printing, and freeing linked lists.
- │
- ├── ´shell.h´
- │   - Header file containing function prototypes and definitions.
- │
- ├── ´environ.c´
- │   - Source code for managing the shell environment.
- │   - Includes functions for printing the environment and manipulating environment variables.
- │
- ├── ´main.c´
- │   - Main source code file for the shell program.
- │   - Contains the main execution of the shell and command parsing.
- │
- └── ´README.md´
    - Project documentation in Markdown format, including project description and usage instructions.


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

- [BRAHIM EL HOUSS](https://github.com/EL-HOUSS-BRAHIM) - Owner
- [AYOUB KIAL](https://github.com/Kialayoub) - Owner

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
