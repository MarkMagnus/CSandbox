/* 
 * File:   main.cpp
 * Author: mark
 *
 * Created on 13 August 2010, 6:46 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include "IntegerSetInterface.h"
#include "IntegerBinarySearchTree.h"
#include "IntegerBitSearcher.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int size = 10;
    int max_value = 1000;

    //IntegerBinarySearchTree searcher(size, max_value);
    IntegerBitSearcher searcher(size, 10000000);

    printf("visualize bit map shifting\n");

    for(int j = 0; j < 100; j++){
        printf("%d - %d\n", j, searcher.bit_map_shift(j));
    }

    printf("visualize bit map masking\n");

    for(int j = 0; j < 100; j++){
        printf("%d - %d - %d\n", j, searcher.bit_wise(j), searcher.bit_map_mask(j));
    }

    printf("inserting\n");

    searcher.insert(50);

//    if(searcher.test_bit_map_for(50)){
//        printf("50 inserted\n");
//    } else {
//        printf("50 not inserted!\n");
//    }

    searcher.insert(1);
    searcher.insert(5);
    searcher.insert(80);
    searcher.insert(560);
    searcher.insert(4);
    searcher.insert(34);
    searcher.insert(87);
    searcher.insert(45);
    searcher.insert(13);


    //int count = searcher.count();
    //printf("count %d\n", count);

    //int sum = searcher.sum();
    //printf("sum %d\n", sum);

    printf("searching\n");

    int * report = new int[size];
    searcher.report(report);

    for(int i = 0; i < size; i++){
        printf("%d\n", report[i]);
    }

    return (EXIT_SUCCESS);
}

