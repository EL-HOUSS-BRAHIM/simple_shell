# Simple Unix Shell Project

## Overview

This is a simple Unix command-line shell implementation for the ALX SE program. The project aims to create a basic shell that can execute commands, handle built-in functions, and provide a user-friendly command-line interface. This project is a collaborative effort by [BRAHIM EL HOUSS] and [AYOUB KIAL].

## Project Details

- Project Name: Simple Unix Shell
- Project Start Date: October 4, 2023, 4:00 AM
- Project Deadline: October 19, 2023, 4:00 AM
- Checker Release Date: October 17, 2023, 11:12 PM

## Project Description

The goal of this project is to create a functional Unix shell that can handle the following tasks:

- Execute external commands
- Handle built-in functions (exit, env, cd, etc.)
- Implement basic input and output redirection (optional)
- Manage variables and special variables (e.g., $? and $$)
- Handle logical operators (&& and ||) (optional)
- Support command separators (;) (optional)
- Handle comments in user input (optional)
- Read and execute commands from a file (optional)
- Implement aliases (optional)

## Project Structure

The project is organized into several source files to maintain code modularity and readability:

- `main.c`: Contains the main function to start the shell.
- `helpers.c`: Provides utility functions for error handling, string manipulation, and memory management.
- `builtins.c`: Implements built-in shell commands like exit, env, and cd.
- `execution.c`: Handles the execution of external commands and input/output redirection.
- `tokenization.c`: Tokenizes user input into command arguments.
- `path_handling.c`: Manages the PATH variable and searches for executable commands.
- `error_handling.c`: Provides error-handling functions and displays error messages.
- `memory.c`: Manages memory allocation and deallocation.
- `variables.c`: Manages special shell variables like $? and $$.
- `alias.c` (optional): Implements alias functionality.
- `comments.c` (optional): Handles comments in user input.
- `logical_operators.c` (optional): Supports logical operators (&& and ||).
- `command_separator.c` (optional): Handles command separators (;).
- `file_input.c` (optional): Reads and executes commands from a file.

## Compilation

You can compile the shell using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

To run the shell in interactive mode, simply execute the compiled binary:

```bash
./hsh
```

You can then enter commands and interact with the shell. The shell will display a prompt and execute the entered commands.

## Task Progress

- Task 0: Betty would be proud - Completed
- Task 1: Simple shell 0.1 - In Progress
- Task 2: Simple shell 0.2 - Not Started
- Task 3: Simple shell 0.3 - Not Started
- Task 4: Simple shell 0.4 - Not Started
- Task 5: Simple shell 1.0 - Not Started
- Task 6: Simple shell 0.1.1 (Optional) - Not Started
- Task 7: Simple shell 0.2.1 (Optional) - Not Started
- Task 8: Simple shell 0.4.1 (Optional) - Not Started
- Task 9: setenv, unsetenv (Optional) - Not Started
- Task 10: cd (Optional) - Not Started
- Task 11: ; (Optional) - Not Started
- Task 12: && and || (Optional) - Not Started
- Task 13: alias (Optional) - Not Started
- Task 14: Variables (Optional) - Not Started
- Task 15: Comments (Optional) - Not Started
- Task 16: File as input (Optional) - Not Started

## Contribution Guidelines

If you are working on a specific task or file, please update the task progress above to indicate your current status (In Progress, Completed, Not Started). This helps in tracking the project's development.

## License

This project is licensed under the [License Name] License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

- [Julien Barbier](https://twitter.com/julienbarbier42) for providing guidance and project details.
- [ALX Software Engineering](https://intranet.alxswe.com) for the learning opportunity.

```
