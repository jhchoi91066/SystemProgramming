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
