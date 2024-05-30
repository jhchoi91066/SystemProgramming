# SystemProgramming
리눅스 우분투 프로그래밍


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
