
#include "random.h"
#include <string.h>

char * randomString(int string_sz){
    char * string = (char *) malloc(string_sz*sizeof(char) + 1);

    int i;
    for(i = 0; i < string_sz; i++){
        char c = randomChar();
        string[i] = c;
    }
    string[string_sz] = '\0';

    return string;
}

char randomChar(){
    char alphabet[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int randomNumber = randomInteger(0, 51);
    char randomCharacter = alphabet[randomNumber];
    return randomCharacter;
}

int randomInteger(int low, int high){

  float ratio = (float)rand() / (float)RAND_MAX;
  int randomNumber = ((high - low) * ratio) + low;
  return randomNumber;

}


