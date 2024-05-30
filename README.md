# SystemProgramming
리눅스 우분투 프로그래밍

# 프로젝트 개요

이 프로젝트는 시스템 프로그래밍 과제로, 다양한 시스템 프로그래밍 기법을 활용하여 파일 관리, 프로세스 관리, IPC(프로세스 간 통신) 등을 구현합니다.

## 파일 구조

GPT
프로젝트 파일 구조와 코드
1. 프로젝트 파일 구조
css
코드 복사
project/
│
├── src/
│   ├── main.c
│   ├── main.h
│   ├── file_operations.c
│   ├── file_operations.h
│   ├── system_info.c
│   ├── system_info.h
│   ├── process_management.c
│   ├── process_management.h
│   ├── ipc.c
│   ├── ipc.h
│   ├── sysv_ipc.c
│   ├── sysv_ipc.h
│
├── Makefile
├── chat.log
├── README.md
└── description.mp4
2. 코드 작성
main.c

c
코드 복사
#include "main.h"
#include "file_operations.h"
#include "system_info.h"
#include "process_management.h"
#include "ipc.h"
#include "sysv_ipc.h"

int main() {
    // 예시 코드: 파일 생성 및 읽기
    create_file("example.txt", "Hello, World!");
    read_file("example.txt");

    // 예시 코드: 시스템 정보 출력
    print_file_info("example.txt");

    // 예시 코드: 자식 프로세스 생성 및 실행
    create_process();

    // 예시 코드: IPC 사용
    use_pipes();
    use_signals();

    // 예시 코드: 시스템 V IPC 사용
    use_message_queue();
    use_shared_memory();

    return 0;
}
main.h

c
코드 복사
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#endif
file_operations.c

c
코드 복사
#include "file_operations.h"

void create_file(const char *filename, const char *content) {
    FILE *fp = fopen(filename, "w");
    if (fp != NULL) {
        fprintf(fp, "%s\n", content);
        fclose(fp);
    } else {
        perror("File creation failed");
    }
}

void read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }
        fclose(fp);
    } else {
        perror("File reading failed");
    }
}
file_operations.h

c
코드 복사
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdio.h>

void create_file(const char *filename, const char *content);
void read_file(const char *filename);

#endif
system_info.c

c
코드 복사
#include "system_info.h"
#include <sys/stat.h>
#include <time.h>

void print_file_info(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) == 0) {
        printf("File size: %ld bytes\n", fileStat.st_size);
        printf("File modified: %s", ctime(&fileStat.st_mtime));
    } else {
        perror("File info retrieval failed");
    }
}
system_info.h

c
코드 복사
#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include <stdio.h>

void print_file_info(const char *filename);

#endif
process_management.c

c
코드 복사
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
process_management.h

c
코드 복사
#ifndef PROCESS_MANAGEMENT_H
#define PROCESS_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>

void create_process();

#endif
ipc.c

c
코드 복사
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
ipc.h

c
코드 복사
#ifndef IPC_H
#define IPC_H

#include <stdio.h>
#include <stdlib.h>

void signal_handler(int signum);
void use_pipes();
void use_signals();

#endif
sysv_ipc.c

c
코드 복사
#include "sysv_ipc.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <string.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

void use_message_queue() {
    int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    struct msgbuf message;
    message.mtype = 1;
    strcpy(message.mtext, "Hello, World!");
    msgsnd(msgid, &message, sizeof(message), 0);
}

void use_shared_memory() {
    int shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, NULL, 0);
    strcpy(str, "Hello, World!");
    printf("Data written in memory: %s\n", str);
    shmdt(str);
}
sysv_ipc.h

c
코드 복사
#ifndef SYSV_IPC_H
#define SYSV_IPC_H

#include <stdio.h>
#include <stdlib.h>

void use_message_queue();
void use_shared_memory();

#endif
Makefile

makefile
코드 복사
CC = gcc
CFLAGS = -Wall
TARGET = main

all: $(TARGET)

$(TARGET): main.o file_operations.o system_info.o process_management.o ipc.o sysv_ipc.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o file_operations.o system_info.o process_management.o ipc.o sysv_ipc.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

file_operations.o: file_operations.c file_operations.h
	$(CC) $(CFLAGS) -c file_operations.c

system_info.o: system_info.c system_info.h
	$(CC) $(CFLAGS) -c system_info.c

process_management.o: process_management.c process_management.h
	$(CC) $(CFLAGS) -c process_management.c

ipc.o: ipc.c ipc.h
	$(CC) $(CFLAGS) -c ipc.c

sysv_ipc.o: sysv_ipc.c sysv_ipc.h
	$(CC) $(CFLAGS) -c sysv_ipc.c

clean:
	rm -f $(TARGET) *.o
README.md

markdown
코드 복사
# 프로젝트 개요

이 프로젝트는 시스템 프로그래밍 과제로, 다양한 시스템 프로그래밍 기법을 활용하여 파일 관리, 프로세스 관리, IPC(프로세스 간 통신) 등을 구현합니다.

## 파일 구조

project/
│
├── src/
│ ├── main.c
│ ├── main.h
│ ├── file_operations.c
│ ├── file_operations.h
│ ├── system_info.c
│ ├── system_info.h
│ ├── process_management.c
│ ├── process_management.h
│ ├── ipc.c
│ ├── ipc.h
│ ├── sysv_ipc.c
│ ├── sysv_ipc.h
│
├── Makefile
├── chat.log
├── README.md
└── description.mp4



## 빌드 및 실행 방법

1. 프로젝트 폴더로 이동
2. 빌드
3. 실행
4. 클린업


## 구현 내용

- **파일 입출력**
- 파일 생성, 읽기, 쓰기 기능
- **시스템 정보**
- 파일 메타데이터 조회 기능
- **프로세스 관리**
- 프로세스 생성 및 exec 함수 사용
- **IPC**
- 파이프, 시그널, 메모리 매핑 기능
- **시스템 V IPC**
- 메시지 큐, 공유 메모리 사용




