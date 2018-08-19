#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int main(int argc, char const *argv[])
{
    pid_t pid;
    int x = 1;
    if ((pid = fork()) < 0) {
        printf("fork error\n");
        exit(0);
    }
    if (pid == 0) {
        sleep(1);
        printf("\n\n\n\n\n\n");
        exit(0);
    }
    printf("I'm father\n");
    exit(0);
    return 0;
}
