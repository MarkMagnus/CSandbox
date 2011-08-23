/* 
 * File:   main.c
 * Author: mark
 *
 * Created on 6 October 2010, 7:38 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "anagram.h"
#include "fileUtil.h"
#include "hashmap.h"

#define DICTIONARY_FILE "dictionary.txt"
#define DICTIONARY_HASH_FILE "dictionary.hash.txt"
#define ANAGRAM_FILE "anagram.txt"

void testAssumptions(){
    size_t alphabet_sz = 52;
    char alphabet[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i;
    for(i = 0; i < alphabet_sz; i++){
      char c = alphabet[i];
      char l_c = charToLower(c);
      char u_c = charToUpper(c);
      printf("%c - %d - %c - %c\n", c, c, l_c, u_c );
    }

    char text[256] = "BeForeTHEDawn";
    printf("Unconverted: %s\n", text);
    toLower(text);
    printf("Converted: %s\n", text);

    char a = 'a';
    char b = 'b';
    char e = 'e';

    printf("%d\n", charCompare(&a, &b));
    printf("%d\n", charCompare(&e, &e));
}

void generateDictionaryHash(){
    /*
     * HASH DICTIONARY FILE
     */

    char * fileName = DICTIONARY_FILE;
    RFILE * rfile = openRFile(fileName);

    char * hashFileName = DICTIONARY_HASH_FILE;
    deleteFile(hashFileName);
    WFILE * wfile = openWFile(hashFileName);

    int position = 0;
    char * text = "";
    signature * s;
    char * hash;
    char line[4096];

   while(readLineFromRFile(rfile, &text, &position) == 0){

     s = getSignature(text);
     normalizeSignature(s, hash, 256);
     sprintf(line, "%s,%s" , hash, text);
     printf("%s\n" , line);
     appendLineToWFile(wfile, line);
   }

   closeRFile(rfile);
   closeWFile(wfile);

}

void flattenHashDictionaryFile(){
    /*
     * FLATTEN HASH FILE SO ANAGRAMS ON SAME LINE BEHIND HASH
     */

    // read file into hash map
    char * dictionaryFile = DICTIONARY_FILE;
    RFILE * rlookup = openRFile(dictionaryFile);

    size_t map_sz = 100000; // expect number of values
    size_t attr_sz = 256;   // expected length of values
    hashmap * map = createHashMap(map_sz, attr_sz);

    printf("map size: %d\n", map->array_sz);

    int rlookupPosition = 0; // flagging current position
    char * rlookupText = (char *) malloc(sizeof(char) * attr_sz);
    char * hash = (char *) malloc(sizeof(char) * attr_sz);

    while(readLineFromRFile(rlookup, &rlookupText, &rlookupPosition) == 0){

         signature * s = getSignature(rlookupText);
         if(normalizeSignature(s, hash, attr_sz) == HASH_SUCCESS){
             printf("%s - %s\n", hash, rlookupText);
             appendEntry(map, hash, rlookupText);
         } else {
             printf("error\n");
         }
         free(s);
    }

    free(rlookupText);
    free(hash);

    closeRFile(rlookup);

    // write hash map to file
    
    WFILE * anagrams = openWFile(ANAGRAM_FILE);
    
    int i;    
    char line[4096];
    for(i = 0; i < map->array_sz; i++ ){
        if(strcmp(map->keys[i], EMPTY_HASH_KEY) != 0){
            sprintf(line, "%s,%s" , map->keys[i], map->values[i]);
            printf("%s\n", line);
            appendLineToWFile(anagrams, line);
        }
    }
    closeWFile(anagrams);
    
    destroyHashMap(map);

}

int main(int argc, char** argv) {
    
    //testAssumptions();
    //generateDictionaryHash();
    flattenHashDictionaryFile();
    
    return (EXIT_SUCCESS);
}

