#include <stdint.h>
#include <stdio.h>
#include "anagram.h"

signature * getBlankSignature(){
    signature * s = (signature *) malloc(sizeof(signature));
    int i;
    for(i = 0; i < 256; i++){
        s->counters[i] = 0;
    }
    return s;
}

/*
 * Get Signature is used for whole words where
 * the output signature is dictated but the following
 * hash syntax. <char><count><char><count><char><count>
 * ie
 *  hello => e1h1l2o1
 * NB letters are alphabetical
 */
signature * getSignature(char word[]){
    signature * s = getBlankSignature();

    //toLower(word);

    int i;
    for(i = 0; ;i++){
        char c = word[i];

        if(c == '\0'){
            return s;
        }

        s->counters[(int) c]++;
    }
    return s;
}


hash_error_code normalizeSignature(signature * s, char * hash ,size_t hash_sz){
    int i;
    
    // clear
    for(i = 0; i < hash_sz; i++){
        hash[i] = '\0';
    }

    int j = 0;
    for(i = 0; i < hash_sz; i++){
        int c = s->counters[i];
        if ( c != 0 ) {
            sprintf(hash, "%s%c%d", hash, i, c);
        }
    }

    return HASH_SUCCESS;
}

int charCompare(char * a, char * b){
    return *a - *b;
}

char charToLower(char c){
    if ( (int) c >= 65 && (int) c <= 90 ){
        return (char) ((int) c + 32);
    }
    return c;
}

char charToUpper(char c){
    if ( (int) c >= 97 && (int) c <= 122 ){
        return (char) ((int) c - 32);
    }
    return c;
}

void toLower(char text[]){
    int i;
    for(i = 0;  ; i++){
        char c =  text[i];
        if (c == '\0'){ return; }
        char new_c = charToLower(c);
        //printf("%c - %c\n", c, new_c);
         text[i] = new_c;
    }
}

