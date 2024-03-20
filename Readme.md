This program simulates an operating system kernel. It manages processes
using a priority queue and runs them in a simulated CPU.
 
# StyleConventions
Naming Conventions: 
Variables are in camelCase
Structs are in PascalCase
Functions are in snake_case with ModuleName as prefix

 For example, pKernal, ProcessControlBlock and operatingSystem_Constructor.
 *
 * The main components of the program are:
 * - The OperatingSystem structure, which represents the kernel.
 * - The ProcessControlBlock structure, which represents a process.
 *
 * The program runs in a loop until the initial process is terminated.
 * During each iteration of the loop, it accepts a user command and performs
 * an action based on that command.
 *
 * The possible actions are:
 * - If the command is 'q', the program runs one iteration of the CPU. It
 *   selects a process from the priority queue and runs it for a quantum of
 *   time. If the process's time reaches 0, the process is terminated and
 *   removed from the queue.
 * - If the command is 'k', the program terminates the initial process and
 *   exits the loop.
 * - If the command is any other character, the program does nothing.
 *
 * The program assumes that the user will enter valid commands. It does not
 * perform any error checking on the user input.