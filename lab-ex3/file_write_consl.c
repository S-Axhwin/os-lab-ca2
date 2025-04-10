#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("file1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char ch;
    ssize_t bytes_read;

    write(STDOUT_FILENO, "Start typing (end with $):\n", 28);

    while (1) {
        bytes_read = read(STDIN_FILENO, &ch, 1);  // read 1 char from console

        if (bytes_read == -1) {
            perror("read");
            break;
        }

        if (ch == '$') {
            break;
        }

        write(fd, &ch, 1);  // write to file
    }

    close(fd);
    return 0;
}
