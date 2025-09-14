# Extended Report on Fork & Exec Assignments in C Programming

## Repository and Structure

All assignments and this report are hosted in the GitHub repository:
[https://github.com/RealGevorgian/fork\_exec\_assignment.git](https://github.com/RealGevorgian/fork_exec_assignment.git)

Repository structure:

```
fork_exec_assignment/
├── src/
│   ├── assignment0.c  # Multiple fork calls to create a process tree
│   ├── assignment1.c  # Simple fork and exec with ls command
│   ├── assignment2.c  # Multiple forks and execs with ls and date commands
│   ├── assignment3.c  # Fork and exec with echo command and arguments
│   ├── assignment4.c  # Fork and exec with grep command and arguments
│   └── test.txt       # Sample text file for assignment4
├── report.md          # Detailed report with code and analysis
└── README.md          # Project documentation
```

---

## Introduction

This report documents the development and analysis of programming assignments focused on the `fork` and `execl` system calls in C, conducted as part of an operating systems course. The assignments explore process creation, program replacement, and argument passing in a Unix-like environment. The work is informed by class lectures and the textbook chapter available at [https://github.com/aragevorgyan/aua-os.git](https://github.com/aragevorgyan/aua-os.git). The implementations were tested on an Ubuntu system.

---

## Assignment 0: Multiple Fork Calls

### Objective and Implementation

The goal of this assignment is to understand the process hierarchy resulting from multiple sequential `fork` system calls. The program creates a process tree by invoking `fork` three times in succession. Sample code:

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 == -1) {
        perror("Fork 1 failed");
        exit(1);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("Fork 2 failed");
        exit(1);
    }

    pid3 = fork();
    if (pid3 == -1) {
        perror("Fork 3 failed");
        exit(1);
    }

    printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
    sleep(1);
    return 0;
}
```

### Execution Flow and Analysis

The program begins as a single process that executes three `fork` calls. Each `fork` doubles the number of processes, resulting in eight total processes. Each prints its PID and PPID. The hierarchy can be visualized using:

```bash
pstree -p $(pidof assignment0)
```

---

## Assignment 1: Simple Fork and Exec

### Objective and Implementation

This assignment demonstrates creating a child process with `fork` and replacing it with `ls` using `execl`.

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0) {
        execl("/bin/ls", "ls", NULL);
        perror("execl failed");
        exit(1);
    } else {
        printf("Parent process done\n");
    }
    return 0;
}
```

The child executes `ls`, while the parent prints its message.

---

## Assignment 2: Multiple Forks and Execs

### Objective and Implementation

This program creates two child processes: one runs `ls`, the other runs `date`.

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == -1) {
        perror("Fork 1 failed");
        exit(1);
    }
    if (pid1 == 0) {
        execl("/bin/ls", "ls", NULL);
        perror("execl ls failed");
        exit(1);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("Fork 2 failed");
        exit(1);
    }
    if (pid2 == 0) {
        execl("/bin/date", "date", NULL);
        perror("execl date failed");
        exit(1);
    }

    printf("Parent process done\n");
    return 0;
}
```

The parent prints after creating both children. Outputs may interleave depending on scheduling.

---

## Assignment 3: Fork and Exec with Arguments

### Objective and Implementation

This assignment shows how to pass arguments to `execl`. The child process executes `echo` with a custom message.

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0) {
        execl("/bin/echo", "echo", "Hello from the child process", NULL);
        perror("execl failed");
        exit(1);
    } else {
        printf("Parent process done\n");
    }
    return 0;
}
```

The parent prints after the child executes `echo`.

---

## Assignment 4: Fork and Exec with Command-Line Arguments

### Objective and Implementation

This assignment uses `grep` to search for the word "main" in `test.txt`.

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0) {
        execl("/bin/grep", "grep", "main", "test.txt", NULL);
        perror("execl failed");
        exit(1);
    } else {
        printf("Parent process completed\n");
    }
    return 0;
}
```

Sample `test.txt`:

```
This is a test file.
It contains main.
No match here.
Main function example.
```

The child runs `grep`, and the parent signals completion.

---

## Report Details

Report Date: September 14, 2025
Author: Gevorg
