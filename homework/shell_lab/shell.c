#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();

    int status, i;

    if (pid > 0)
    {
        pid_t waitPid;
        printf("processing...\n");
        waitPid = wait(&status);

        if (waitPid == -1)
        {
            char *msg;
            msg = strerror(errno);
            printf("error:%s\n", msg);
        };
        printf("completed.\n");
    }
    else if (pid == 0)
    {
        if (execvp(argv[1], &argv[1]) == -1)
        {
            fprintf(stderr, "error:%s\n", strerror(errno));
            return 1;
        }
        return 0;
    }

    return 0;
}
