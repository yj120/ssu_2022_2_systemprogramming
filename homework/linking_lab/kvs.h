#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

struct node
{
    char key[100];
    char *value;
    struct node *next;
};
typedef struct node node_t;

struct kvs
{
    struct node *db; // database
    int items;       // number of data
};
typedef struct kvs kvs_t;

kvs_t *open();
node_t *open_node();
int close(kvs_t *kvs); // free all memory space
int put(kvs_t *kvs, const char *key, char *value);
char *get(kvs_t *kvs, char *key);
void seek(kvs_t *kvs); // print all items in alphabetical order. return the number of items.
