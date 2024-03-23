# Project Title

## Overview

This project simulates an operating system kernel that manages processes using a priority queue and runs them in a simulated CPU.

## Components

The main components of the program are:

- `OperatingSystem`: This structure represents the kernel of the operating system.
- `ProcessControlBlock`: This structure represents a process in the operating system.

## Execution

The program runs in a loop until the initial process is terminated. During each iteration of the loop, it accepts a user command and performs an action based on that command.

## User Commands

- `Q`: Runs one iteration of the CPU. It selects a process from the priority queue and runs it for a quantum of time. If the process's time reaches 0, the process is terminated and removed from the queue.
- `K`: Terminates the process of the indicated Process ID (PID). If the killed process was the initial process, the program exits the loop.
- Any other character: The program does nothing.

## Style Conventions

- Variables are in camelCase (e.g., `pKernal`)
- Structs are in PascalCase (e.g., `ProcessControlBlock`)
- Functions are in snake_case with the module name as a prefix (e.g., `operatingSystem_Constructor`)

## Assumptions

[Provide any assumptions made during the development of the project here]

# Complete
ProcInfo
TotalInfo
Kernal
Quantum 
# In Progress

 # Todo
 -Exit Parm (Easy)
 
 -Kill Parm (Hard)

 -Semaphores (Medium)
 -IPC (Hard)