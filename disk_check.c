#include <stdio.h>
#include <sys/statvfs.h>

int main(void) {
    struct statvfs fs;

    if (statvfs("/", &fs) != 0) { perror("statvfs failed"); return 1; }

    unsigned long long total; // max disk
    unsigned long long free;
    unsigned long long avail;
    unsigned long long used_sys;
    unsigned long long used_user;


    total = fs.f_blocks * fs.f_frsize;
    free = fs.f_bfree * fs.f_frsize;
    avail = fs.f_bavail * fs.f_frsize;
    used_sys = total - free;
    used_user = total - avail;

    printf("[Disk Information]\n");
    printf("---------------------\n");
    printf("Total          : %llu MB\n", total / 1024 / 1024);
    printf("Used (system)  : %llu MB\n", used_sys / 1024 / 1024);
    printf("Used (user)    : %llu MB\n", used_user / 1024 / 1024);
    printf("Available      : %llu MB\n", avail / 1024 / 1024);
    printf("Free           : %llu MB\n", free / 1024 / 1024);

    return 0;
}
