# File System Calls

1. open  (both read and write)
2. close (close the file)
3. read  (only to read the file)
4. write (only to write into the file)
5. lseek (to move the file cursor to specified pos)
6. unlink(deletes a file by name)
7. rename(reanames a file)
8. link  (creates hard or symbolic link to files.)

change the permission of user
`
sudo chown otherusername sample.txt
ls -l sample.txt
`

hard link
```c
#include <unistd.h>
#include <stdio.h>

int main() {
    if (link("sample.txt", "sample_link.txt") == -1) {
        perror("link");
        return 1;
    }

    return 0;
}

```
test
`ls -li sample.txt sample_link.txt`




