#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    int sourceFd = open("source.txt", O_RDONLY);
    if (sourceFd == -1) {
        perror("open source");
        return 1;
    }

    int copyFd = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (copyFd == -1) {
        perror("open copy");
        close(sourceFd);
        return 1;
    }

    // Get file size
    off_t fileSize = lseek(sourceFd, 0, SEEK_END);
    if (fileSize == -1) {
        perror("lseek");
        close(sourceFd);
        close(copyFd);
        return 1;
    }

    // Ask user for input
    char choice;
    write(STDOUT_FILENO, "Enter 1 (first half) or 2 (second half): ", 41);
    read(STDIN_FILENO, &choice, 1);

    off_t start = 0;
    off_t half = fileSize / 2;
    off_t length = half;

    if (choice == '2') {
        start = half;
        // For odd-sized files, second half gets the extra byte
        length = fileSize - half;
    }

    // Move to starting point
    if (lseek(sourceFd, start, SEEK_SET) == -1) {
        perror("lseek set");
        close(sourceFd);
        close(copyFd);
        return 1;
    }

    // Read and write the entire portion at once
    char *buffer = malloc(length);


    ssize_t bytesRead = read(sourceFd, buffer, length);
    if (bytesRead > 0) {
        write(copyFd, buffer, bytesRead);
    }

    free(buffer);

    close(sourceFd);
    close(copyFd);
    write(STDOUT_FILENO, "\nCopy completed to copy.txt\n", 29);
    return 0;
}
