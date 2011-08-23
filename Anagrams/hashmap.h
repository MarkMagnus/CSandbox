/*
 * File:   hashMap.h
 * Author: mark
 *
 * Created on 20 October 2010, 10:14 PM
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _HASHMAP_H
#define	_HASHMAP_H

#ifdef	__cplusplus
extern "C" {
#endif



struct map {
    size_t array_sz;
    size_t attr_sz;
    char ** keys;
    char ** values;
    int * hash;
};

typedef struct map hashmap;

#define EMPTY_HASH_KEY "NULL"
#define EMPTY_HASH_VALUE ""
#define EMPTY_HASH 0
#define HASH_PRIME 29989111
#define HASH_MULTIPLIER 31

hashmap * createHashMap(size_t array_sz, size_t attr_sz);
void destroyHashMap(hashmap * map);
int findEntry(hashmap * map, const char * key);
void insertEntry(hashmap * map, const char * key, const char * value);
void removeEntry(hashmap * map, const char * key);
void appendEntry(hashmap * map, const char * key, const char * value);
unsigned int hash(const char * plainText);


#ifdef	__cplusplus
}
#endif

#endif	/* _HASHMAP_H */

