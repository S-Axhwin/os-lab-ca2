#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of fork() calls (n): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        // Only the child should continue to fork, parent breaks
        if (pid > 0) {
            break;
        }
    }

    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    sleep(1);  // Just to prevent fast exit, optional

    return 0;
}
