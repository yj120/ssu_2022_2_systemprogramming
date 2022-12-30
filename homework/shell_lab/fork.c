#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("I am child:%ld\n", (long)getpid());
    }
    else if (pid > 0)
    {
        printf("I am parent:%ld\n", (long)getpid());
    }
    else
    {
        printf("fork Fail! \n");
        return -1;
    }
    return 0;
}
