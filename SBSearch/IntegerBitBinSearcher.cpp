/* 
 * File:   IntegerBitBinSearcher.cpp
 * Author: mark
 * 
 * Created on 18 August 2010, 10:26 PM
 */

#include "IntegerBitBinSearcher.h"

IntegerBitBinSearcher::IntegerBitBinSearcher(int max_elements, int max_value) {
    bins = max_elements;
    max_integer_value = max_value;
    bin = new node*[bins];
    sentinal = new node(max_integer_value, 0);
    for(int i = 0 ; i < bins; i++){
        bin[i] = sentinal;
    }
    n = 0;
}

IntegerBitBinSearcher::IntegerBitBinSearcher(const IntegerBitBinSearcher& orig) {
}

IntegerBitBinSearcher::~IntegerBitBinSearcher() {
}

int IntegerBitBinSearcher::size(){
    return n;
}

void IntegerBitBinSearcher::insert(int t){
    int i = t / (1 + max_integer_value/bins);
    bin[i] = rinsert(bin[i], t);
}

void IntegerBitBinSearcher::report(int * r){
    int j = 0;
    int * report = new int[n];
    for(int i = 0; i < bins; i++){
        for(node *p = bin[i]; p != sentinal; p = p->next){
            report[j++] = p->value;
        }
    }
    r = report;
}

