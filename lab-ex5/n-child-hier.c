#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    /*
        P1 -> P2 -> P3
    */
    pid_t p2, p3;

    printf("P1 (Parent) PID: %d, PPID: %d\n", getpid(), getppid());

    p2 = fork(); // P1 creates P2

    if (p2 == 0) {
        // Inside P2
        printf("P2 (Child of P1) PID: %d, PPID: %d\n", getpid(), getppid());

        p3 = fork(); // P2 creates P3

        if (p3 == 0) {
            // Inside P3
            printf("P3 (Child of P2) PID: %d, PPID: %d\n", getpid(), getppid());
        }

        // Optional: Let P2 wait so P3 can print
        sleep(1);
    }

    // Optional: Let P1 wait so P2 can print
    sleep(2);
    return 0;
}
