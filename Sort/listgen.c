
#include "random.h"
#include "listgen.h"

int * generateRandomIntegerList(int size, int low, int high){
    int * integers = (int *) malloc(sizeof(int)*size);
    int i;
    for(i = 0; i < size; i++){
        integers[i] =  randomInteger(low, high);
    }
    return integers;
}