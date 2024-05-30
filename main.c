// 채팅 로그 저장
FILE *logFile = fopen("chat.log", "a");
if (logFile != NULL) {
    fprintf(logFile, "User1: Hello, World!\n");
    fclose(logFile);
}

// 채팅 로그 읽기
logFile = fopen("chat.log", "r");
if (logFile != NULL) {
    char buffer[100];
    while (fgets(buffer, 100, logFile) != NULL) {
        printf("%s", buffer);
    }
    fclose(logFile);
}
