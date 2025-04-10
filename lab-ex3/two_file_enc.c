#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define SHIFT 3

int main() {
    int inputFd = open("original.txt", O_RDONLY);
    int outputFd = open("encrypted.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    char buffer[1024];
    ssize_t bytesRead;

    while ((bytesRead = read(inputFd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytesRead; i++) {
            if ((buffer[i] >= 32 && buffer[i] <= 126)) {
                buffer[i] = ((buffer[i] - 32 + SHIFT) % 95) + 32;
            }
        }
        write(outputFd, buffer, bytesRead);
    }

    close(inputFd);
    close(outputFd);

    write(STDOUT_FILENO, "File encrypted successfully to encrypted.txt\n", 45);
    return 0;
}
