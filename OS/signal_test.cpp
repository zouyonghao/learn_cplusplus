#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigproc() {
    signal(SIGINT, sigproc);
    printf("you have pressed ctrl-c - disabled \n");
}

void quitproc() {
    printf("ctrl-\\ pressed to quit\n");
    exit(0);
}

main() {
    signal(SIGINT, sigproc);
    signal(SIGQUIT, quitproc);
    printf("ctrl-c disabled and use ctrl-\\ to quit\n");
    for (;;);;
}