# Simple Shell Program

This is a simple Unix-like shell program written in C that provides basic shell functionality, including command execution, environment variable management, and built-in commands.

## Table of Contents
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Features](#features)
- [Built-in Commands](#built-in-commands)
- [Contributing](#contributing)
- [License](#license)
- [
[BRAHIM EL HOUSS] and [AYOUB KIAL]
## Project Structure

The project structure is organized into several source code files to maintain modularity and readability. Here's an overview of the project structure:

### Source Code Files

1. **main.c**: The entry point of the shell program, responsible for starting the shell and managing user input and command execution.

2. **prompt.c**: Contains functions related to displaying the shell prompt and reading user input.

3. **execute.c**: Handles command execution, including running external commands and built-in shell commands.

4. **helper.c**: Provides utility functions for string manipulation, tokenization, and memory management.

5. **builtins.c**: Defines built-in shell commands like `exit`, `env`, `setenv`, `unsetenv`, and `cd`.

6. **environ.c**: Manages environment variables, including functions to get, set, and unset environment variables.

7. **getline.c**: Contains a custom `getline` function to read lines from a file stream, enhancing user input handling.

8. **str_funcs.c**: Defines functions for string manipulation, including tokenization, whitespace trimming, and variable replacement.

9. **utility_funcs.c**: Contains utility functions like string length calculation, string comparison, and memory management.

### Header Files

- **shell.h**: Contains function prototypes, necessary system library includes, and macro definitions for the entire project.

### Other Files

- **Makefile**: Defines build instructions for compiling the shell program.

## Usage

To compile and run the shell program, follow these steps:

1. Clone the repository: `git clone <repository-url>`
2. Navigate to the project directory: `cd simple-shell`
3. Compile the code: `make`
4. Run the shell: `./shell`

The shell prompt will appear, allowing you to enter commands.

## Features

- Command execution (both external commands and built-in commands).
- Environment variable management (get, set, unset).
- Built-in commands: `exit`, `env`, `setenv`, `unsetenv`, `cd`.
- Custom `getline` function for enhanced user input handling.
- Variable substitution (e.g., replacing `$VAR` with the value of the environment variable `VAR`).

## Built-in Commands

- `exit`: Exit the shell program.
- `env`: Display the current environment variables.
- `setenv VAR VALUE`: Set an environment variable `VAR` with the given `VALUE`.
- `unsetenv VAR`: Unset (remove) an environment variable `VAR`.
- `cd [DIRECTORY]`: Change the current working directory to `DIRECTORY` (default is the user's home directory).

## Contributing

Contributions to this project are welcome! If you'd like to contribute, please follow these guidelines:

1. Fork the repository.
2. Create a new branch for your feature or bug fix: `git checkout -b feature/your-feature-name` or `git checkout -b bugfix/your-bug-fix`.
3. Make your changes and commit them: `git commit -m "Your commit message here"`.
4. Push your changes to your fork: `git push origin feature/your-feature-name` or `git push origin bugfix/your-bug-fix`.
5. Create a pull request to the `main` branch of this repository.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
