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
