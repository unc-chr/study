/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：getcwd1.c
*   Author：leekaihua
*   Date：2024年05月18日
*   Brife：
*



*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

#if 0
struct dirent {
    ino_t          d_ino;       /* inode number */
    off_t          d_off;       /* not an offset; see NOTES */
    unsigned short d_reclen;    /* length of this record */
    unsigned char  d_type;      /* type of file; not supported
                                    by all file system types */
    char           d_name[256]; /* filename */
};
#endif

int main() {
    DIR* dir = nullptr;
    struct dirent* d = nullptr;
    // 1 open dir test
    dir = opendir("test");
    if (dir == nullptr) {
        perror("opendir");
        return 1;
    }
    printf("open dir successfully...\n");
    // 2 read dir
    while (true) {
        d = readdir(dir);
        if (d == nullptr) {
            perror("readdir");
            break;
        }
        printf("d_type:%hu d_name:%s\n", d->d_type, d->d_name);
    }

    // 3 close dir
    closedir(dir);
    printf("close dir successfully...\n");

    return 0;
}