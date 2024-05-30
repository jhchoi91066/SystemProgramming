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
