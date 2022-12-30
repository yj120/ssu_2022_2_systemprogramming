#include "kvs.h"

int main()
{
    // 1. create KVS
    void *handle = dlopen("./libkvs.so", RTLD_LAZY);
    kvs_t *(*open)() = NULL;
    open = dlsym(handle, "open");
    kvs_t *kvs = open();
    if (!kvs)
    {
        printf("Failed to open kvs\n");
        return -1;
    }
    // 2. put data
    // 1) file read
    // 2) put data

#if 1
    int (*put)(kvs_t *, char *, char *) = NULL;
    put = dlsym(handle, "put");
    printf("Put operation ...\n");
    FILE *fp;
    char buffer[1000];
    // char *buffer = malloc(sizeof(char)*50);
    char *token;
    char key[100];
    char *value = (char *)malloc(sizeof(char) * 300);
    int p = 0;
    fp = fopen("student.dat", "r");
    if (fp == NULL)
    {

        puts("파일을 생성할 수 없습니다.");
        exit(0); // (0) 정상 중단, (1) 오류 중단
    };
    while (!feof(fp))
    {
        memset(buffer, 0, 1000);
        fgets(buffer, 1000, fp);
        if (buffer == NULL)
        {
            break;
        };
        token = strtok(buffer, " ");
        int i = 0;
        while (token != NULL)
        {
            if (i == 0)
            {
                strcpy(key, token);
            }
            else if (i == 1)
            {

                strcpy(value, token);
                if (put(kvs, key, value) < 0)
                {
                    printf("failed to put data\n");
                    exit(-1);
                };
            };

            i++;
            token = strtok(NULL, " ");
        };
        if (buffer[0] == '\n')
        {
            break;
        }
        if (feof(fp) && buffer[0] == '\n')
        {
            break;
        };
        // puts(buffer);
    };
    fclose(fp);

#endif
#if 1
    printf("\n");

    char *(*get)(kvs_t *, char *) = NULL;
    get = dlsym(handle, "get");

    printf("\nGet operation ...\n");
    FILE *fpp = fopen("student.dat", "r");
    char *tok;
    char buff[1000];
    char checkbuff[1000];
    char *check;
    char *rvalue;
    if (fpp == NULL)
    {
        puts("파일을 생성할 수 없습니다.");
        exit(0); // (0) 정상 중단, (1) 오류 중단
    };
    memset(buff, 0, 1000);
    while (!feof(fpp))
    {
        memset(buff, 0, 1000);
        fgets(buff, 1000, fpp);
        if (buff == NULL)
        {
            break;
        };
        tok = strtok(buff, " ");
        int i = 0;
        while (tok != NULL)
        {
            if (i == 0)
            {
                strcpy(key, tok);
                rvalue = get(kvs, key);
                if (!(rvalue = get(kvs, key)))
                {
                    printf("Failed to get data\n");
                    break;
                };
                printf("get: %s %s", key, rvalue);
            }
            i++;
            tok = strtok(NULL, " ");
        };
        if (buff[0] == '\n')
        {
            break;
        }
        if (feof(fpp) && buff[0] == '\n')
        {
            break;
        };
    };
    fclose(fpp);

#endif
    // 4. print all items seek

#if 1
    printf("\n\n");
    void (*seek)(kvs_t *) = NULL;
    seek = dlsym(handle, "seek");
    seek(kvs);
    // printf("%d items are found\n", nitems);

    // 5. close
    int (*close)(kvs_t *) = NULL;
    close = dlsym(handle, "close");
    close(kvs);
#endif
    return 0;
};
