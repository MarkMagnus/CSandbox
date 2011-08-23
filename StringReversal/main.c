/* 
 * File:   main.c
 * Author: mark
 *
 * Created on 1 October 2010, 9:46 AM
 */

#include <stdio.h>
#include <stdlib.h>

void swap(char array[], size_t array_sz, int from_pos, int to_pos){
    char temp = array[from_pos];
    array[from_pos] = array[to_pos];
    array[to_pos] = temp;
}

void replace(char array[], size_t array_sz, int from_pos, int to_pos, char c){
    int swap_size = to_pos - from_pos;
    int i;
    for(i = from_pos; i != to_pos + 1; i++){
        array[i] = c;
    }
}

void reverse(char array[], size_t array_sz, int pos, int length){
    int i;
    int from_pos = pos;
    int to_pos = (pos + length);
    while(from_pos < to_pos){
        //printf("fp: %d tp: %d \n", from_pos, to_pos);
        swap(array, array_sz, from_pos, to_pos);
        from_pos++;
        to_pos--;
    }
}

void printArray(char array[], size_t array_sz){
    int i;
    for(i = 0; i < array_sz; i++){
        printf("%c", array[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {

    size_t array_sz = 23;
    char array[23] = "the cat sat on the mat";
    //char * ptr_array = &array;

    reverse(array, array_sz, 0, 7);
    printArray(array, array_sz);
    reverse(array, array_sz, 8, 14);
    printArray(array, array_sz);
    reverse(array, array_sz, 0, 22);
    printArray(array, array_sz);
/*
    printArray(array, array_sz);
    swap(array, array_sz, 4, 19);
    printArray(array, array_sz);
    replace(array, array_sz, 8, 10, 'v');
    printArray(array, array_sz);
*/

    return (EXIT_SUCCESS);
}

