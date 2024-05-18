/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：stat6.c
*   Author：leekaihua
*   Date：2024年05月18日
*   Brife：
*



*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#if 0
struct stat {
    dev_t     st_dev;         /* ID of device containing file */
    ino_t     st_ino;         /* inode number */
    mode_t    st_mode;        /* file type and mode */
    nlink_t   st_nlink;       /* number of hard links */
    uid_t     st_uid;         /* user ID of owner */
    gid_t     st_gid;         /* group ID of owner */
    dev_t     st_rdev;        /* device ID (if special file) */
    off_t     st_size;        /* total size, in bytes */
    blksize_t st_blksize;     /* blocksize for filesystem I/O */
    blkcnt_t  st_blocks;      /* number of 512B blocks allocated */

    /* Since Linux 2.6, the kernel supports nanosecond
        precision for the following timestamp fields.
        For the details before Linux 2.6, see NOTES. */

    struct timespec st_atim;  /* time of last access */
    struct timespec st_mtim;  /* time of last modification */
    struct timespec st_ctim;  /* time of last status change */

    #define st_atime st_atim.tv_sec      /* Backward compatibility */
    #define st_mtime st_mtim.tv_sec
    #define st_ctime st_ctim.tv_sec
};
#endif

int show_file_type(struct stat* s) {
    switch(s->st_mode & S_IFMT) {
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFDIR:
            printf("folder\n");
            break;
        case S_IFCHR:
            printf("char device\n");
            break;
        case S_IFBLK:
            printf("block device\n");
            break;
        case S_IFLNK:
            printf("symbolic link\n");
            break;
        case S_IFSOCK:
            printf("socket\n");
            break;
        case S_IFIFO:
            printf("FIFO\n");
            break;
        default:
            printf("unknown file type!\n");
    }

    return 0;
}

// 权限
int show_permission(struct stat* s) {
    printf("user permission: ");
    if (s->st_mode & S_IRUSR) {
        printf("r");
    } else {
        printf("-");
    }
    if (s->st_mode & S_IWUSR) {
        printf("w");
    } else {
        printf("-");
    }
    if (s->st_mode & S_IXUSR) {
        printf("x");
    } else {
        printf("-");
    }
    printf("\n");

    printf("group permission: ");
    if (s->st_mode & S_IRGRP) {
        printf("r");
    } else {
        printf("-");
    }
    if (s->st_mode & S_IWGRP) {
        printf("w");
    } else {
        printf("-");
    }
    if (s->st_mode & S_IXGRP) {
        printf("x");
    } else {
        printf("-");
    }
    printf("\n");

    printf("other permission: ");
    if (s->st_mode & S_IROTH) {
        printf("r");
    } else {
        printf("-");
    }
    if (s->st_mode & S_IWOTH) {
        printf("w");
    } else {
        printf("-");
    }
    if (s->st_mode & S_IXOTH) {
        printf("x");
    } else {
        printf("-");
    }
    printf("\n");

    return 0;
}

// 获取文件的类型和权限
int main(int argc, char** argv) {
    int ret = -1;
    struct stat s;
    // 容错判断
    if (argc != 2) {
        printf("usage: ./a.out filename\n");
        return 1;
    }
    // 获取指定文件的信息
    ret = stat(argv[1], &s);
    if (ret == -1) {
        perror("stat");
        return 1;
    }

    // 显示文件的类型
    show_file_type(&s);
    show_permission(&s);

    return 0;
}