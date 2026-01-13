#include <stdio.h>
#include <string.h>

int main(void) {
    FILE* fp;
    char line[256];

    fp = fopen("/proc/net/dev", "r");
    if (fp == NULL) {
        perror("failed to open /proc/net/dev");
        return 1;
    }

    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);

    printf("[Network Status]\n");

    while (fgets(line, sizeof(line), fp)) {
        char iface[32];
        unsigned long long rx, tx;

        sscanf(line,
            " %31[^:]: %llu %*llu %*llu %*llu %*llu %*llu %*llu %*llu %llu",
            iface, &rx, &tx);

        if (strcmp(iface, "lo") == 0)
            continue;

        printf("Interface: %s\n", iface);
        printf(" RX: %.2f MB\n", rx / 1024.0 / 1024.0);
        printf(" TX: %.2f MB\n\n", tx / 1024.0 / 1024.0);
    }

    fclose(fp);
    return 0;
}

