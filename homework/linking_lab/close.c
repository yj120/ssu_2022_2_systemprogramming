#include "kvs.h"

int close(kvs_t *kvs)
{
    if(kvs){
        free(kvs);
    };

   
    return 0;
}