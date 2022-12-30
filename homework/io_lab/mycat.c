#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFF_SIZE 16

int main(int argc, char *argv[])
{
    int ifd, ofd; // ifd -> input file, ofd ->outputfd
    char *buff;
    int nbytes;

    if (argc < 2)
    {
        fprintf(stdout, "No arguments\n");
        return 0;
    }
    else if (argc == 2)
    {
        ofd = STDOUT_FILENO; // 상수 집어넣고
    }
    else if (argc == 4 && !strcmp(argv[2], "into"))
    {
        // output to redirection file
        ifd = open(argv[1], O_RDONLY);
        buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
        if ((ofd = open(argv[3], O_RDWR | O_CREAT, S_IRWXU)) < 0)
        {
            fprintf(stderr, "ERROR");
            return 1;
        }
        while ((nbytes = read(ifd, buff, BUFF_SIZE)) > 0)
        {
            write(ofd, buff, BUFF_SIZE);
        }
        // write(nbytes,buff,strlen(buff));
        return 0;
    }
    else
    {
        fprintf(stdout, "Wrong arguments\n");
        return 0;
    }

    // Open input file
    ifd = open(argv[1], O_RDONLY); // 읽기 전용으로 읽어오기

    // Allocate buffer
    if (!(buff = (char *)malloc(sizeof(char) * BUFF_SIZE)))
    {
        fprintf(stdout, "Failed to allocate memory\n");
        exit(-1);
    }
    // Copy files
    while ((nbytes = read(ifd, buff, BUFF_SIZE)) > 0)
    {
        write(ofd, buff, BUFF_SIZE);
    };

    // Close files
    close(ifd);
    close(ofd);
}
