#include "process_management.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void create_process() {
    pid_t pid = fork();
    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        perror("exec failed");
        exit(1);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("fork failed");
    }
}
