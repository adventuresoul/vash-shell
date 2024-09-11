# Vash-Shell

**Vash-Shell** is a custom shell program built from scratch, implementing core Linux shell functionalities with a focus on exploring and applying fundamental operating system concepts. This project is designed to simulate the behavior of a Linux shell, providing users with an interface to interact with the system kernel, execute commands, manage processes, and handle file systems.

> **Note**: The project is still under development and currently supports executing only system binaries.

## Features

- **Command Execution**: Supports executing basic Unix commands such as `ls`, `cd`, `pwd`, `echo`, and more.
- **Process Management**: Implements concepts of process creation using **fork()**, process termination, and background/foreground process execution using **exec()** and **wait()**.

## Operating System Concepts Applied

- **Process Control**: The shell manages processes using **fork()** to create child processes, **exec()** to execute programs, and **wait()** to wait for process completion. It also handles background and foreground processes.
- **Inter-process Communication (IPC)**: Pipes are used to demonstrate inter-process communication, allowing the output of one command to be passed as input to another.

## Technologies Used

- **C Programming Language**: The shell is implemented in C, emphasizing low-level system programming and interaction with the Linux kernel.
- **Linux/Unix System Calls**: Utilizes system calls like **fork()**, **exec()**, **wait()**, and **kill()** for process management and **dup2()** for I/O redirection.

## Future Enhancements

- **Advanced Scripting**: Adding support for shell scripting, allowing users to write scripts with conditional statements and loops.
- **Job Control Enhancements**: Improving job control by adding job suspension and resumption features.
- **Command History**: Implementing command history with support for recalling and executing previously entered commands.
- **Tab Completion**: Adding tab completion for better user experience in navigating directories and commands.
