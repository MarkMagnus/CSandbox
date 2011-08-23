#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

int bitMask32(int integer){
    return integer & BITMAP_MASK;
}

int shift(int integer){
    return integer >> BITMAP_SHIFT;
}

void add(int integer){
    BITMAP[shift(integer)] |= (1 << bitMask32(integer));
}

int test(int integer){
    return BITMAP[shift(integer)] & (1 << bitMask32(integer));
}

void clear(int integer){
    BITMAP[shift(integer)] &= ~(1 << bitMask32(integer));
}

void sortIntegers(int ** integers, int ** size){
    
    int i;
    
    // clear bitmap
    for(i = 0; i < BITMAP_SIZE; i++){ 
        clear(i);
    }


    int * unsortedIntegers = *integers;

    // sort
    int unique = 0;
    int integer = 0;
    for(i = 0; i < **size; i++){
        integer = unsortedIntegers[i];
        if(test(integer) == 0){
            add(integer);
            unique++;
        }
    }

    // output
    int * sortedIntegers = (int *) malloc(sizeof(int) * unique );
    int count = 0;
    for(i = 0; i < BITMAP_SIZE; i++){
        if(test(i)){
            printf("%d\n", i);
            sortedIntegers[count] = i;
            count++;
        }
    }

    int * ptr_unique = &unique;

    *integers = sortedIntegers;
    *size = ptr_unique;
}
