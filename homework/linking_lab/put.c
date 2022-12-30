#include "kvs.h"

int put(kvs_t *kvs, const char *key, char *value)
{
    printf("put: %s %s", key, value);

    // char *v = (char *)malloc(sizeof(char) * 300);

    if (kvs->db == NULL)
    {
        node_t *head = (node_t *)malloc(sizeof(node_t));
        head->value = (char *)malloc(sizeof(char) * 300);
        kvs->db = head;
        strcpy(head->key, key);
        strcpy(head->value, value);
        head->next = NULL;
    }
    else
    {
        node_t *curr = kvs->db;
        while (curr->next != NULL)
        {
            curr = curr->next;
        };
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        strcpy(new_node->key, key);
        new_node->value = (char *)malloc(sizeof(char) * 300);
        new_node->next = NULL;
        strcpy(new_node->value, value);
        curr->next = new_node;
    }

    return 0;
}
