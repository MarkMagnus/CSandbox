
#include <stdio.h>
#include <stdlib.h>

#include "hashmap.h"

int main(int argc, char** argv) {

    size_t array_sz = 10;
    size_t attr_sz = 256;
    hashmap * map = createHashMap(array_sz, attr_sz);
    insertEntry(map, "name", "Mark");
    insertEntry(map, "middle", "Joesph");
    insertEntry(map, "surname", "Magnus");
    removeEntry(map, "middle");
    insertEntry(map, "age", "30");
    appendEntry(map, "message", "hello");
    appendEntry(map, "message", "world");
    insertEntry(map, "name", "Duncan");

    int i;
    for(i = 0; i < map->array_sz; i++){
        printf("%d-%s-%s\n", i, map->keys[i], map->values[i]);
    }
    destroyHashMap(map);

    return (EXIT_SUCCESS);
}

