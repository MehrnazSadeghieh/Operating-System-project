# operating system
In this code we are controlling the access of common datas in multi-threaded program and use both mutex and semaphore.

### Multi-Threaded Data Access Control
Overview
This codebase is designed to provide a practical solution for controlling access to shared data in a multi-threaded program. It employs a combination of mutexes and semaphores to ensure data integrity and synchronization among threads. This README will guide you through the project's structure, usage, and key concepts.


### Motivation
Multi-threaded programming is essential for achieving parallelism and efficient resource utilization. However, it also introduces challenges, such as data access synchronization, that need to be addressed to avoid race conditions and data corruption. This codebase addresses the need for a robust mechanism to manage shared data access in multi-threaded programs.

### Getting Started
Before using this code, ensure you have a compatible C/C++ development environment set up. The following libraries may be required, depending on your platform and compiler:

Pthread: POSIX threads library for thread management.
Semaphore: Libraries for semaphores, or the equivalent provided by your platform.
To compile the code, use your preferred C/C++ compiler:

```
gcc -o your_program source.c -lpthread -lsemaphore
```

### Usage
Clone this repository or download the source files.

Compile the source code as mentioned in the "Getting Started" section.

Execute the compiled program.

The program will demonstrate the usage of mutexes and semaphores to control access to shared data among multiple threads.

### Key Features
Mutexes: Mutexes (short for mutual exclusion) are used to protect critical sections of code, ensuring only one thread can access shared data at a time.

Semaphores: Semaphores allow you to control access to a shared resource, managing the number of threads that can access it concurrently.

Thread Synchronization: The codebase demonstrates techniques to synchronize multiple threads effectively, preventing race conditions and data corruption.

Sample Implementation: A working example is provided to showcase the application of mutexes and semaphores in a multi-threaded environment.

