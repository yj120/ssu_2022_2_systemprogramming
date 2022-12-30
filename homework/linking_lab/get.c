#include "kvs.h"

char *get(kvs_t *kvs, char *key)
{
    /* do program here */

    char *value = (char *)malloc(sizeof(char) * 100);
    char *temp = (char *)malloc(sizeof(char) * 100);

    if (!value)
    {
        printf("Failed to malloc\n");
        return NULL;
    };

    node_t *cur = kvs->db;
    while (cur != NULL)
    {

        if (strcmp(cur->key, key) == 0)
        {
            strcpy(temp, cur->value);
            break;
        };
        cur = cur->next;
    }

    strcpy(value, temp);
    return value;
}
