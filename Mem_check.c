#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
memory info == total ram , cached , avilable ram , used ram(total ram - avilable ram)
swap info == swap total , swap used (swap total - swap free)
*/

int main(void) {
	FILE* fp;
	char line[256];

	long mem_total = 0;
	long mem_available = 0;
	long mem_cached = 0;
	long swap_total = 0;
	long swap_used = 0;

	int is_mem_total = 0;
	int is_mem_availabe = 0;
	int is_mem_cached = 0;
	int is_swap_total = 0;
	int is_swap_free = 0;

	fp = fopen("/proc/meminfo", "r");
	if (fp == NULL) { perror("meminfo open failed"); return 1; }

	printf("\n[Memory Info]\n");

	while (fgets(line, sizeof(line), fp)) {

		if (strncmp(line, "MemTotal", 8) == 0) { sscanf(line, "MemTotal: %ld kB", &mem_total); is_mem_total = 1; }

		else if (strncmp(line, "MemAvailable", 12) == 0) { sscanf(line, "MemAvailable: %ld kB", &mem_available); is_mem_availabe = 1; }

		else if (strncmp(line, "Cached", 6) == 0) { sscanf(line, "Cached: %ld kB", &mem_cached); is_mem_cached = 1; }

		else if (strncmp(line, "SwapTotal", 9) == 0) { sscanf(line, "SwapTotal: %ld kB", &swap_total); is_swap_total = 1; }

		else if (strncmp(line, "SwapFree", 8) == 0) { long swap_free = 0; sscanf(line, "SwapFree: %ld kB", &swap_free); swap_used = swap_total - swap_free; is_swap_free = 1; }

		if (mem_total && mem_available && mem_cached && is_swap_total && is_swap_free) { break; }
	}

	printf("Total RAM     : %.2f GB\n", mem_total / 1024.0 / 1024.0);
	printf("Used RAM      : %.2f GB\n",
		(mem_total - mem_available) / 1024.0 / 1024.0);
	printf("Cached        : %.2f GB\n", mem_cached / 1024.0 / 1024.0);
	printf("Available RAM : %.2f GB\n", mem_available / 1024.0 / 1024.0);

	printf("\n[Swap Info]\n");
	printf("Swap Total    : %.2f GB\n", swap_total / 1024.0 / 1024.0);
	printf("Swap Used     : %.2f GB\n", swap_used / 1024.0 / 1024.0);

	return 0;
}
