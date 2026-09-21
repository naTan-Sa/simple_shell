# Simple Shell

## Description

**Simple Shell** is a simple UNIX command-line interpreter written in C.

This project is part of the ALX Software Engineering curriculum and is designed to help us understand how a shell works, including processes, system calls, environment variables, and command execution.

The shell provides an interface where users can enter commands and receive output from the operating system.

## Features

The shell will support:

* Displaying a prompt and waiting for user input
* Reading and parsing commands
* Executing commands
* Handling commands with arguments
* Searching for commands using the `PATH` environment variable
* Handling errors
* Supporting built-in commands
* Handling the `EOF` condition
* Handling interactive and non-interactive modes

## Compilation

The project can be compiled using:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Usage

Run the shell in interactive mode:

```bash
./hsh
```

Example:

```text
$ ./hsh
($) /bin/ls
file1  file2  main.c
($) pwd
/home/user/simple_shell
($) exit
```

The shell can also receive commands through standard input:

```bash
echo "/bin/ls" | ./hsh
```

## Built-in Commands

The shell will implement built-in commands such as:

* `exit`
* `env`

Additional built-ins may be added as the project develops.

## Project Structure

```text
simple_shell/
├── AUTHORS
├── README.md
├── main.c
├── ...
└── ...
```

## Authors

* Natan Sahlu

## Requirements

* Ubuntu/Linux
* GCC
* Git

## Learning Objectives

Through this project, i aim to understand:

* How a UNIX shell works
* Processes and process creation
* `fork()`
* `execve()`
* `wait()`
* File descriptors
* Environment variables
* The `PATH` variable
* System calls
* Memory management
* Error handling

## License

This project is for educational purposes as part of the ALX Software Engineering program.

