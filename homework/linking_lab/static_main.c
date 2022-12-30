#include "kvs.h"

int main()
{
	// 1. create KVS
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
	printf("Put operation ...\n");
	FILE *fp;
	char buffer[1000];
	char *token;
	char key[100];
	char *value = (char *)malloc(sizeof(char) * 300);
	char *rvalue;
	fp = fopen("student.dat", "r");
	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
		exit(0); // (0) 정상 중단, (1) 오류 중단
	};
	while (!feof(fp))
	{
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

	// 3. get for test

	// 1) file read
	// 2) get & compare return value with original vallue

#if 1
	int debug = 0; // 디버깅용
	printf("\n");
	printf("\nGet operation ...\n");
	FILE *fpp = fopen("student.dat", "r");
	char *tok;
	char buff[1000];
	char checkbuff[1000];
	char *check;
	int check_count = 0;
	if (fpp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
		exit(0); // (0) 정상 중단, (1) 오류 중단
	};
	while (!feof(fpp))
    {
    check_count = 0;
    memset(buff,0,1000);

    /*if((fgets(buff,1000,fpp)==NULL)){
        break;};
    */
        fgets(buff, 1000, fpp);
        if (buff == NULL)
        {
            break;
        };
    //printf("buff: %s\n",buff);
        tok = strtok(buff, " ");
        int i = 0;
        while (tok != NULL)
        {

        if (i == 0)
            {
                strcpy(key, tok);
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
    if (buff[0]=='\n'){
        break;};
        if (feof(fpp) && buff[0] == '\n')
        {
            break;
        };
    };
    fclose(fpp);
#endif

    // 4. print all items
#if 1
    printf("\n\n");
   // int nitems = seek(kvs);
    seek(kvs);
    close(kvs);
#endif

	return 0;
}
