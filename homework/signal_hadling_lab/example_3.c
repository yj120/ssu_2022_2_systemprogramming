#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#define NUM 8

int ccount = 0;

void child_handler2(int sig)
{
    fprintf(stdout, "child_handler2... \n");
    int status;

    pid_t pid;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        ccount--;
        fprintf(stdout, "Received signal %d from process %d\n", sig, pid);
    }
}

int main(int argc, void *argv[])
{
    pid_t pid[NUM];
    int i, status;

    ccount = NUM;

    signal(SIGCHLD, child_handler2);

    for (i = 0; i < NUM; i++)
    {
        if ((pid[i] = fork()) == 0)
        {
            sleep(2);
            exit(0);
        }
    }
    while (ccount > 0)
        pause();
}
