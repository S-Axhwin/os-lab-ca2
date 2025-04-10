#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int no_of_lines(char *filePath) {
    int fd = open(filePath, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[1024];
    ssize_t bytes_read;
    int line_count = 0;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                line_count++;
            }
        }
    }

    if (bytes_read == -1) {
        perror("read");
    }

    close(fd);

    printf("Total lines: %d\n", line_count);
    return line_count;
}

int main() {
    char *text = "../text.txt";
    int lines = no_of_lines(text);
    
    int lines_cp = lines/2;
    printf("lines to show: %d\n",lines_cp);


    int fd = open(text, O_CREAT, 0644);
    char data[100];
    read(fd,data, 100);
    printf("%s", data);
    return 0;
}
