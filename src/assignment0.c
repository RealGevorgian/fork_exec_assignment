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
