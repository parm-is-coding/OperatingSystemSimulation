# Project Title

## Overview

This project simulates an operating system kernel that manages processes using a multilevel priority queue and runs them in a simulated single core CPU.

## Components

The main components of the program are:

- `OperatingSystem`: This structure represents the kernel of the operating system.
- `ProcessControlBlock`: This structure represents a process in the operating system.

## Execution

The program runs in a loop until the initial process is terminated. During each iteration of the loop, it accepts a user command and performs an action based on that command.

## User Commands
- `C` : prompts for a priority level then creates and assigns a Process Control Block data structure, which represents processes, to the appropriate ready queue 

- `Q`: Runs one iteration of the CPU. It selects a process from the priority queue and runs it for a quantum of time. 

- `E`: destroys the currently running process and schedules the next running process to run, if the currently running process is initProcess the program is ended however this is only possible if there are no other processes on the queues.

- `K`: Terminates the process of the indicated Process ID (PID). If the killed process was the initial process, and there are no other processes the program ends. it is assumed that users dont kill processes that are Blocked or waiting on Senders or receivers.

- `N` : prompts for a semaphore value ranging from 0 to 4, 

- `P` : prompts the user for a process Id then displays the attributes of the process on the terminal

- `T`: displays all the processes in the system

- Any other character: The program does nothing.

## Style Conventions

- Variables are in camelCase (e.g., `pKernal`)
- Structs are in PascalCase (e.g., `ProcessControlBlock`)
- Functions are in snake_case with the module name as a prefix (e.g., `operatingSystem_Constructor`)

## Assumptions

[Provide any assumptions made during the development of the project here]

A process can only have 1 sender waiting at a time
init process cant call send/receive/reply (if init process is running wont be anyone to receive/reply to anyways)

# Complete
ProcInfo
TotalInfo
Kernal
Quantum (Bug RoundRobin not scheduling properly)
# In Progress

 