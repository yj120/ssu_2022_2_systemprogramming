#include "kvs.h"

void seek(kvs_t *kvs)
{
    printf("Seek operation ...\n");
    node_t *cur = kvs->db;
    char test[100];
    char *k, *v;
    char *comma = ",";
    char *temp;
    char text_list[10][100];
    char *t_list[10];
    int count = 5;

    int n = 0;
    while (cur != NULL)
    {
        k = cur->key;
        v = cur->value;
        sprintf(test, "%s%s%s", k, comma, v);
        // printf("%s", test);
        strcpy(text_list[n], test);
        n++;
        cur = cur->next;
    };

    for (int i = 0; i < 5; i++)
    {
        // printf("%s\n", text_list[i]);
        t_list[i] = text_list[i];
    };

    for (int step = 0; step < count - 1; step++)
    {
        for (int i = 0; i < count - 1 - step; i++)
        {
            if (strcmp(t_list[i], t_list[i + 1]) > 0)
            {
                temp = t_list[i];
                t_list[i] = t_list[i + 1];
                t_list[i + 1] = temp;
            }
        }
    };
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; t_list[i][j] != 0; j++)
        {
            if (t_list[i][j] == '\n')
            {
                t_list[i][j] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("(%s)\n", t_list[i]);
    };

    return;
}
