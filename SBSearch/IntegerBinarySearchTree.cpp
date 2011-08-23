/* 
 * File:   IntegerBinarySearchTree.cpp
 * Author: mark
 * 
 * Created on 15 August 2010, 3:09 PM
 */

#include "IntegerBinarySearchTree.h"

IntegerBinarySearchTree::IntegerBinarySearchTree(int max_nr_elements, int max_integer_value) {
    root = 0;
    n = 0;
    values = new int[max_nr_elements];
}

IntegerBinarySearchTree::IntegerBinarySearchTree(const IntegerBinarySearchTree& orig) {
}

IntegerBinarySearchTree::~IntegerBinarySearchTree() {
}

void IntegerBinarySearchTree::insert(int t){
    root = rinsert(root, t);
}
void IntegerBinarySearchTree::report(int * v){
    values = v;
    vn = 0;
    traverse(root);
}

int IntegerBinarySearchTree::count(){

        return rcount(root);
    }

int IntegerBinarySearchTree::sum(){

        return rsum(root);
    }


