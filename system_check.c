#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
FILE *fp;
char line[256];
int is_model = 0;
int is_cores = 0;
int is_mhz = 0;

fp = fopen("/proc/cpuinfo" , "r");
if (fp == NULL) { perror("cpuinfo open failed! "); return 0;}
printf("[CPU inpo]\n");

while (fgets(line , sizeof(line) , fp)) {

if (strncmp(line , "model name" , 10) == 0)
{
char *value = strchr(line , ':'); 
if (value != NULL) {value += 2; printf("Model Name : %s" , value); }
is_model = 1;
}

if (strncmp(line , "cpu cores" , 9) == 0)
{
char *value  = strchr(line , ':');
if (value) { value += 2; int cores = atoi(value); printf("Cpu Cores : %d\n" , cores); }
is_cores = 1;
}

if (strncmp(line , "cpu MHz" , 7) == 0)
{
char *value =  strchr(line, ':');
if (value) { value += 2; double mhz = atof(value); printf("Cpu MHz : %.2f\n",mhz); }
is_mhz = 1;
}

if (is_model && is_cores && is_mhz) { break; }

}

fclose(fp);

return 0;

}
