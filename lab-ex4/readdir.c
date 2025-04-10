#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int main () {
    char folderName[] = "ashwin";
    DIR *dir = opendir(folderName);
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        printf("  %s\n", entry->d_name);
    }
}