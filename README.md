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

# 🔗 Hard Link vs Symbolic Link in Linux/Unix

| Feature | Hard Link | Symbolic Link (Symlink / Soft Link) |
|--------|------------|-------------------------------------|
| 🔢 **Inode** | Shares same inode as the original file | Has a different inode, just points to the file path |
| 🏷️ **Name** | Another name for the same file | A pointer (shortcut) to the file |
| 🧱 **File Exists?** | File exists as long as at least one link exists | If original file is deleted, symlink becomes broken (dangling) |
| 🧭 **Path Based?** | No (directly refers via inode) | Yes (follows file path) |
| 📁 **Across Partitions?** | ❌ Not allowed across different file systems or partitions | ✅ Allowed across different partitions |
| 🔄 **Circular Links?** | ❌ Not possible | ✅ Possible (but bad practice) |
| 📂 **Can link to directories?** | ❌ Usually not allowed (for safety) | ✅ Allowed |
| 🧾 **Example** | `link("file.txt", "hardlink.txt");` | `symlink("file.txt", "symlink.txt");` |

---

This table summarizes the key differences between hard links and symbolic links in Unix-like operating systems.

- **Hard links** are essentially additional names for the same file on disk.
- **Symbolic links** (or soft links) are shortcuts that point to the original file path.

Use symbolic links when:
- You want a shortcut to a file or directory.
- You need to link across partitions.

Use hard links when:
- You want multiple persistent names to the same file content.
- You don't need cross-partition links or to link directories.




------------------------------------------------------

# Ex4:

1. opendir
2. readir
3. closedir
4. chdir
5. mkdir
6. rmdir
7. getcwd


### 1. opendir() -> similar to open() but now as a folder
🔍 Opens a directory stream for reading.
```c
DIR *dir = opendir("/path/to/dir");
```

### 2. readdir() -> similar to read() but now as a folder file
```c
struct dirent *entry;
while ((entry = readdir(dir)) != NULL) {
    printf("  %s\n", entry->d_name);
}
```

### 3. closedir -> similar to close() but now as folders.
```c
closedir(dir);
```

### chdir 
```c 
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char cwd[PATH_MAX];

    // Print current directory
    getcwd(cwd, sizeof(cwd));
    printf("Current Directory: %s\n", cwd);

    // Change directory
    if (chdir("/tmp") == 0) {
        getcwd(cwd, sizeof(cwd));
        printf("Changed to: %s\n", cwd);
    } else {
        perror("chdir failed");
    }

    return 0;
}
```

### mkdir
`mkdir("newfolder", 0755);`

### rmdir()
`rmdir("dir_name")`

### getcwd()
Gets the current working directory path.
```c
char path[1024];
getcwd(path, sizeof(path));
printf("Current dir: %s\n", path);
```


```sh
chmod 755 <foldername>
```
