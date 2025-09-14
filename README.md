# Fork and Exec Assignment

This repository contains solutions to assignments demonstrating **process creation** and **program execution replacement** in C using the `fork()` and `execl()` system calls. The exercises build an understanding of how parent and child processes interact in Unix-like operating systems.

---

## Folder Structure

```
fork_exec_assignment/
├── src/
│   ├── assignment0.c  # Multiple fork calls to create a process tree
│   ├── assignment1.c  # Simple fork and exec with ls command
│   ├── assignment2.c  # Multiple forks and execs with ls and date commands
│   ├── assignment3.c  # Fork and exec with echo command and arguments
│   ├── assignment4.c  # Fork and exec with grep command and arguments
│   └── test.txt       # Sample text file for assignment4
├── Report.md          # Detailed report with code and analysis
└── README.md          # This file
```

---

## Assignment 0: Process Tree with Multiple Forks

**Objective:**

* Understand how multiple calls to `fork()` create a process tree.

**Description:**

* The program demonstrates how calling `fork()` multiple times results in a branching structure of parent and child processes.

**Expected Output Example:**

* Multiple process IDs printed, showing parent-child relationships.

---

## Assignment 1: Simple Fork and Exec

**Objective:**

* Learn how to create a child process and replace it with a new program.

**Description:**

* The program uses `fork()` to create a child process.
* In the child process, `execl()` runs the `ls` command to list files in the current directory.
* The parent process prints:

```
Parent process done
```

**Expected Output Example:**

```
file1.c  file2.txt  README.md
Parent process done
```

---

## Assignment 2: Multiple Forks and Execs

**Objective:**

* Work with multiple child processes created using `fork()` and run different commands.

**Description:**

* The program creates **two child processes**.
* First child: runs `ls` using `execl()`.
* Second child: runs `date` using `execl()`.
* The parent process prints:

```
Parent process done
```

**Expected Output Example:**

```
file1.c  file2.txt  README.md
Sat Sep 14 20:30:21 AMT 2025
Parent process done
```

---

## Assignment 3: Fork and Exec with Arguments

**Objective:**

* Understand how to pass arguments to programs executed with `execl()`.

**Description:**

* The program creates a child process.
* The child process runs:

```bash
echo "Hello from the child process"
```

* The parent process prints:

```
Parent process done
```

**Expected Output Example:**

```
Hello from the child process
Parent process done
```

---

## Assignment 4: Fork and Exec with Command-Line Arguments

**Objective:**

* Use `execl()` to run a command with multiple arguments.

**Preparation:**
Create a file `test.txt` with some text, for example:

```
int main() {
    printf("Hello, world!\n");
}
This file contains the word main in multiple places.
```

**Description:**

* The program creates a child process.
* The child process runs:

```bash
grep "main" test.txt
```

* The parent process prints:

```
Parent process completed
```

**Expected Output Example:**

```
int main() {
This file contains the word main in multiple places.
Parent process completed
```

---

## How to Compile and Run

Each assignment should be compiled separately. Example for **Assignment 1**:

```bash
gcc src/assignment1.c -o assignment1
./assignment1
```

For **Assignment 4**, ensure `test.txt` exists before running:

```bash
gcc src/assignment4.c -o assignment4
./assignment4
```

---

## How to Run

1. **Clone the repository:**

   ```bash
   git clone git@github.com:RealGevorgian/fork_exec_assignment.git
   ```

2. **Navigate to the `src` directory:**

   ```bash
   cd fork_exec_assignment/src
   ```

3. **Compile each program:**

   ```bash
   gcc assignmentN.c -o assignmentN  # Replace N with 0, 1, 2, 3, or 4
   ```

4. **Run the program:**

   ```bash
   ./assignmentN
   ```

5. For **assignment4**, ensure `test.txt` exists with sample text containing the word `main`.

---

## Prerequisites

* GCC compiler
* Ubuntu or similar Linux environment
* Git installed for cloning the repository

---

## Notes

* Use the following command in another terminal to visualize process trees (e.g., for `assignment0`):

```bash
pstree -p $(pidof assignmentN)
```

---

## Author

# Gevorg Gevorgyan

AUA Operating Systems Course
Fall 2025
