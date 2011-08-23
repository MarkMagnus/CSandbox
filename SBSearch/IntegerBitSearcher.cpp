/* 
 * File:   IntegerBitSearcher.cpp
 * Author: mark
 * 
 * Created on 17 August 2010, 10:04 PM
 */

#include "IntegerBitSearcher.h"
#include <stdio.h>

IntegerBitSearcher::IntegerBitSearcher(int max_nr_integers, int max_value_integer) {
    highest_value = max_value_integer;
    container = new int[1 + highest_value/BITSPERWORD];
    for(int i = 0; i < highest_value; i++){
         clear_bit_map_at(i);
    }
    n = 0;
}

IntegerBitSearcher::IntegerBitSearcher(const IntegerBitSearcher& orig) {
}

IntegerBitSearcher::~IntegerBitSearcher() {
    container[] delete;
}

void IntegerBitSearcher::insert(int i){
    if(test_bit_map_for(i)){
        return;
    }
    set_bit_map_at(i);
    n++;
}

void IntegerBitSearcher::report(int * r){
    int j = 0;
    int * report = new int[n];
    for(int i = 0; i < highest_value; i++){
        if(test_bit_map_for(i)){
            printf("found[%d] %d\n",j, i);
            r[j++] = i;
        }
    }
    r = report;
}
