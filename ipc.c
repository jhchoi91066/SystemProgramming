#include "ipc.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Received signal %d\n", signum);
}

void use_pipes() {
    int fd[2];
    pipe(fd);
    if (fork() == 0) {
        close(fd[0]);
        write(fd[1], "Hello from child", 17);
        close(fd[1]);
    } else {
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Received: %s\n", buffer);
        close(fd[0]);
    }
}

void use_signals() {
    signal(SIGUSR1, signal_handler);
    if (fork() == 0) {
        kill(getppid(), SIGUSR1);
        exit(0);
    } else {
        wait(NULL);
    }
}
