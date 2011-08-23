/* 
 * File:   anagram.h
 * Author: mark
 *
 * Created on 12 October 2010, 7:39 PM
 */

#ifndef _ANAGRAM_H
#define	_ANAGRAM_H

#ifdef	__cplusplus
extern "C" {
#endif

#define HASH_FAILED 0
#define HASH_SUCCESS 1

// assuming ascii mapping
struct alphabet {
    int counters[256];
};

typedef struct alphabet signature;
typedef int hash_error_code;

signature * getBlankSignature();
signature * getSignature(char word[]);
hash_error_code normalizeSignature(signature * s, char * hash, size_t hash_sz);
int charCompare(char * a, char * b);
char charToLower(char c);
char charToUpper(char c);
void toLower(char text[]);

#ifdef	__cplusplus
}
#endif

#endif	/* _ANAGRAM_H */

