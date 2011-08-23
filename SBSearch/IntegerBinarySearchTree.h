/* 
 * File:   IntegerBinarySearchTree.h
 * Author: mark
 *
 * Created on 15 August 2010, 3:09 PM
 */

#ifndef _INTEGERBINARYSEARCHTREE_H
#define	_INTEGERBINARYSEARCHTREE_H

#include <stdio.h>

class IntegerBinarySearchTree {
public:
    IntegerBinarySearchTree(int max_nr_elements, int max_integer_value);
    IntegerBinarySearchTree(const IntegerBinarySearchTree& orig);
    virtual ~IntegerBinarySearchTree();

    void insert(int t);
    void report(int * v);
    int count();
    int sum();

private:
    int n; // chain length
    int * values;
    int vn;

    struct node {
        int value;
        node * left;
        node * right;
        node(int i){
            value = i;
            left = right = 0;
        }
    };

    node * root;

    node * rinsert(node * parent, int t){
        if (parent == 0) {
            parent = new node(t);
            n++;
        } else if(t < parent->value) {
            parent->left = rinsert(parent->left, t);
        } else if(t > parent->value) {
            parent->right = rinsert(parent->right, t);
        }
        return parent;
    }

    void traverse(node * parent){

        if(parent == 0){
            return;
        }

        if(parent->left != 0){
            traverse(parent->left);
        }

        values[vn++] = parent->value;
        //printf("%d %d\n", vn++, parent->value);

        if(parent->right != 0){
           traverse(parent->right);
         }
    }

    int rsum(node * parent){
        int s = parent->value;
        if (parent->right != 0){
            s += rsum(parent->right);
        }
        if(parent->left != 0){
            s += rsum(parent->left);
        }
        return s;
    }

    int rcount(node * parent){
        int c = 1;
        if (parent->right != 0){
            c += rcount(parent->right);
        }
        if(parent->left != 0){
            c += rcount(parent->left);
        }
        return c;
    }
    
};

#endif	/* _INTEGERBINARYSEARCHTREE_H */

