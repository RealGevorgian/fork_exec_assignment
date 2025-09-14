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
