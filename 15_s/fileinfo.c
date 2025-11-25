#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_time1(const char* label, time_t t);
void print_time2(const char* label, struct timespec ts);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <filepath>\n", argv[0]);
        exit(1);
    }

    struct stat statbuf;
    /* statbuf에 파일정보 읽어오기 */
    stat(argv[1], &statbuf);

    printf("inode = %d\n", (int)statbuf.st_ino);
    printf("mode = %o\n", (unsigned int)statbuf.st_mode);
    printf("nlink = %o\n",(unsigned int) statbuf.st_nlink);
    printf("UID = %d\n", (int)statbuf.st_uid);
    printf("GID = %d\n", (int)statbuf.st_gid);
    printf("size = %d\n", (int)statbuf.st_size);
    printf("blksize = %d\n", (int)statbuf.st_blksize);
    printf("blocks = %d\n", (int)statbuf.st_blocks);
    printf("** timespec Style\n");
    print_time2("Atime", statbuf.st_atim);
    print_time2("Mtime", statbuf.st_mtim);
    print_time2("Ctime", statbuf.st_ctim);
    printf("** old Style\n");
    print_time1("Atime", statbuf.st_atime);
    print_time1("Mtime", statbuf.st_mtime);
    print_time1("Ctime", statbuf.st_ctime);

    return 0;
}

void print_time1(const char* label, time_t t)
{
    char time_str[100];

    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&t));
    printf("%s = %s\n", label, time_str);
}

void print_time2(const char* label, struct timespec ts) {
    char time_str[100];

    struct tm* tm_info;
    tm_info = localtime(&ts.tv_sec);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

    printf("%s = %s.%09ld\n", label, time_str, ts.tv_nsec);
}
