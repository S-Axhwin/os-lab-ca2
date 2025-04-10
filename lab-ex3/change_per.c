#include <sys/stat.h>
#include <stdio.h>

int main() {
    if (chmod("sample.txt", S_IRUSR | S_IWUSR) == -1) {  // 0600
        perror("chmod");
        return 1;
    }

    return 0;
}
