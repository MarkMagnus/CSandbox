/* 
 * File:   main.c
 * Author: mark
 *
 * Created on 3 December 2010, 9:44 PM
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int * array, int to, int from){
    int temp = array[to];
    array[to] = array[from];
    array[from] = temp;
}

int * merge(int * a, size_t a_sz, int * b, size_t b_sz){
    size_t array_sz = (a_sz + b_sz);
    int * array = (int *) malloc(sizeof(int) * array_sz);
    int i;
    int i_a = 0;
    int i_b = 0;
    for(i = 0; i < array_sz; i++){
        //printf("%d < %d\n", a[i_a], b[i_b]);
        if(i_a == a_sz){
            array[i] = b[i_b];
            i_b++;
        } else if (i_b == b_sz) {
            array[i] = a[i_a];
            i_a++;
        } else if(a[i_a] < b[i_b]){
            array[i] = a[i_a];
            i_a++;
        } else {
            array[i] = b[i_b];
            i_b++;
        }
        //printf("%d\n", array[i]);
    }
    return array;
}

int * mergeSort(int * array, size_t array_sz){
    //if length(m) ≤ 1
    //    return m
    printf("array_sz: %d\n", array_sz);
    if(array_sz <= 1) return array;

    //var list left, right, result
    size_t left_sz;
    size_t right_sz;

    if(array_sz % 2 == 0){
        left_sz = right_sz = array_sz / 2;
    } else {
        left_sz = (array_sz / 2 + 1);
        right_sz = array_sz - left_sz;
    }

    printf("left_sz %d\n", left_sz);
    printf("right_sz %d\n", right_sz);

    int * left = (int *) malloc(sizeof(int) * left_sz);
    int * right = (int *) malloc(sizeof(int) * right_sz);
    int * result = (int *) malloc(sizeof(int) * array_sz);
    
    //for each x in m up to middle
    //     add x to left
    printf("right");

    int i;
    for(i = 0; i < left_sz; i++){
        left[i] = array[i];
        printf("-%d", array[i]);
    }

    printf("\nleft");

    //for each x in m after middle
    //     add x to right
    for(i = left_sz; i < array_sz; i++){
        right[i - left_sz] = array[i];
        printf("-%d", array[i]);
    }
    printf("\n");
    
    left = mergeSort(left, left_sz);
    right = mergeSort(right, right_sz);
    result = merge(left, left_sz, right, right_sz);

    return result;
}

void testMergeFunction(){
    size_t a_sz = 4;
    int a[4] = {1,14,15,18};
    size_t b_sz = 6;
    int b[6] = {2,3,6,7,9,10};
    int * array = merge(a, a_sz, b, b_sz);
    int i;
    for(i = 0; i < a_sz + b_sz; i++){
        printf("%d - %d\n", i, array[i]);
    }
    free(array);
}

void testMergeSortFunction(){
    size_t array_sz = 30;
    int array[30] = {29,30,27,28,26,24,25,23,20,21,22,18,19,17,12,13,14,15,16,9,11,10,4,5,1,2,3,8,7,6};

    int i;

    for(i = 0; i < array_sz; i++){
        printf("%d - %d\n", i, array[i]);
    }

    int * sorted = mergeSort(array, array_sz);
    for(i = 0; i < array_sz; i++){
        printf("%d - %d\n", i, sorted[i]);
    }
    free(sorted);

}

int main(int argc, char** argv) {

    //testMergeFunction();
    testMergeSortFunction();
     

/*
    int array_sz = 10;
    int array[10];
    array[0] = 4;
    array[1] = 3;
    array[2] = 6;
    array[3] = 2;
    array[4] = 8;
    array[5] = 1;
    array[6] = 5;
    array[7] = 7;
    array[8] = 9;
    array[9] = 0;

    int i;
    for(i = 0; i < array_sz; i++){
        printf("%d - %d\n", i, array[i]);
    }
*/

    return (EXIT_SUCCESS);
}

