
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"


hashmap * createHashMap(size_t array_sz, size_t attr_sz){

    hashmap * map = NULL;
    char ** keys = NULL;
    char ** values = NULL;
    int * hash = NULL;

    map = calloc(1, sizeof(hashmap));
    keys = (char **) calloc(array_sz, sizeof(char *));
    values = (char **) calloc(array_sz, sizeof(char *));
    hash = (int *) calloc(array_sz, sizeof(int));

    if(map == NULL || keys == NULL || values == NULL || hash == NULL){
        if (map != NULL) free(map);
        if (keys != NULL) free(keys);
        if (values != NULL) free(values);
        if (hash != NULL) free(hash);
        return NULL;
    }

    map->array_sz = array_sz;
    map->attr_sz = attr_sz;
    map->keys = keys;
    map->values = values;
    map->hash = hash;

    // initialize string arrays
    int i;
    for(i = 0; i < array_sz; i++){

        map->keys[i] = (char *) calloc(attr_sz, sizeof(char));
        if(map->keys[i] == NULL){
            destroyHashMap(map);
            return NULL;
        }
        strcpy(map->keys[i], EMPTY_HASH_KEY);


        map->values[i] = (char *) calloc(attr_sz, sizeof(char));
        if(map->values[i] == NULL){
            destroyHashMap(map);
            return NULL;
        }
        strcpy(map->values[i], EMPTY_HASH_VALUE);

        map->hash[i] = EMPTY_HASH;

    }

    return map;
}

void destroyHashMap(hashmap * map){
    int i;
    if(map != NULL){
        if (map->keys != NULL){
            for(i = 0; i < map->array_sz; i++){
                if (map->keys[i] != NULL) free(map->keys[i]);
            }
            free(map->keys);
        }
        if (map->values != NULL){
            for(i = 0; i < map->array_sz; i++){
                if (map->values[i] != NULL) free(map->values[i]);
            }
            free(map->values);
        }
        if(map->hash != NULL) free(map->hash);
        free(map);
    }
}

int findEntry(hashmap * map, const char * key){
    int i;
    int hash_key = hash(key);
    for(i = 0; i < map->array_sz; i++){
        if(map->hash[i] != EMPTY_HASH){
            if (map->hash[i] == hash_key){
                return i;
            }
        }
    }
    return -1;
}

int findFreeIndex(hashmap * map){
    int i;
    for(i = 0; i < map->array_sz; i++){
        if (map->hash[i] == EMPTY_HASH){
            return i;
        }
    }
    return -1;
}

void insertEntry(hashmap * map, const char * key, const char * value){
    int pos = findEntry(map, key);
    if (pos == -1) { pos = findFreeIndex(map); }
    if (pos == -1) { return; }
    map->hash[pos] = hash(key);
    strcpy(map->keys[pos], key);
    strcpy(map->values[pos], value);
}

void appendEntry(hashmap * map, const char * key, const char * value){
    int pos = findEntry(map, key);
    if(pos == -1) {
        insertEntry(map, key, value);
    } else {
        char new[4096];
        sprintf(new, "%s,%s", map->values[pos], value);
        strcpy(map->values[pos], new);
    }
}

void removeEntry(hashmap * map, const char * key) {
    int pos = findEntry(map, key);
    if (pos == -1) { return; }
    map->hash[pos] = EMPTY_HASH;
    strcpy(map->keys[pos], EMPTY_HASH_KEY);
    strcpy(map->values[pos], EMPTY_HASH_VALUE);
}

unsigned int hash(const char * plainText) {
    unsigned int hash = 0;

    for(; *plainText; plainText++) {
        hash = HASH_MULTIPLIER * hash + *plainText;
    }
    return hash % HASH_PRIME;
}