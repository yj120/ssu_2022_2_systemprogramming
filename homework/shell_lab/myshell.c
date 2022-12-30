#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <editline.h>
#include <editline/readline.h>
#include <editline/history.h>

#define MAX_LEN 128

int main(void)
{
    pid_t pid;
    int status;

    while (1)
    {

        char cmdline[MAX_LEN];
        char *opt = strtok(cmdline, " \n");
        char *args[MAX_LEN];
        char **input = args;

        printf("$ ");
        fgets(cmdline, MAX_LEN - 1, stdin);
        cmdline[strlen(cmdline) - 1] = '\0';

        opt = strtok(cmdline, " \n");
        if (!strcmp(opt, "quit"))
            break;

        while (opt != NULL)
        {

            *input++ = opt;
            opt = strtok(NULL, "\n");
        }
        *input = NULL;

        if ((pid = fork()) < 0)
        {
            fprintf(stderr, "fork error");
        }
        else if (pid == 0)
        {
            if (execvp(args[0], args) == -1)
            {
                fprintf(stderr, "error:%s\n", strerror(errno));
                return -1;
            }
        };
        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            fprintf(stderr, "waitpid error");
        };
    }

    exit(0);
}
