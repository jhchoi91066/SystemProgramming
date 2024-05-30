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
