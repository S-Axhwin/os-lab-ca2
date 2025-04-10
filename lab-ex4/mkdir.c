#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char folder_name[MAXNAMLEN];
    scanf("%s", folder_name);

    printf("creating a folder named: %s", folder_name);

    mkdir(folder_name, 755);
    printf("created a folder named: %s", folder_name);

    return 0;
}