#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t p2, p3, p4, p5, p6;

    printf("P1 (PID: %d, PPID: %d)\n", getpid(), getppid());

    p2 = fork();
    if (p2 == 0) {
        // Inside p2
        printf("P2 (PID: %d, PPID: %d)\n", getpid(), getppid());

        p4 = fork();
        if (p4 == 0) {
            // Inside p4
            printf("P4 (PID: %d, PPID: %d)\n", getpid(), getppid());

            p5 = fork();
            if (p5 == 0) {
                // Inside p5
                printf("P5 (PID: %d, PPID: %d)\n", getpid(), getppid());
            }
            sleep(1); // Let p5 print
        }
        sleep(2); // Let p4 & p5 print
    } else {
        p3 = fork();
        if (p3 == 0) {
            // Inside p3
            printf("P3 (PID: %d, PPID: %d)\n", getpid(), getppid());

            p6 = fork();
            if (p6 == 0) {
                // Inside p6
                printf("P6 (PID: %d, PPID: %d)\n", getpid(), getppid());
            }
            sleep(1); // Let p6 print
        }
    }

    sleep(3); // Let all child processes finish printing
    return 0;
}
