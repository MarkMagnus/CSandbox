/* 
 * File:   IntegerSetInterface.cpp
 * Author: mark
 * 
 * Created on 13 August 2010, 6:47 PM
 */

#include "IntegerSetInterface.h"

IntegerSetInterface::IntegerSetInterface(int max_nr_elements, int max_integer_value) {
    n = 0;
    sentinal = head = new node(max_integer_value, 0);
}

IntegerSetInterface::IntegerSetInterface(const IntegerSetInterface& orig) {
}

IntegerSetInterface::~IntegerSetInterface() {
}

void IntegerSetInterface::insert(int t){
    head = rinsert(head, t);
}

int IntegerSetInterface::size(){
    return n;
}

void IntegerSetInterface::report(int * v){
   int j = 0;
   node * p;
   for(p = head; p != sentinal; p = p->next){
       v[++j] = p->val;
   }
}
