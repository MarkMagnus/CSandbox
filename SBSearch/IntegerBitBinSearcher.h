/* 
 * File:   IntegerBitBinSearcher.h
 * Author: mark
 *
 * Created on 18 August 2010, 10:26 PM
 */

#ifndef _INTEGERBITBINSEARCHER_H
#define	_INTEGERBITBINSEARCHER_H

class IntegerBitBinSearcher {
public:
    IntegerBitBinSearcher(int max_elements, int max_integer_value);
    IntegerBitBinSearcher(const IntegerBitBinSearcher& orig);
    virtual ~IntegerBitBinSearcher();

    int size();
    void insert(int t);
    void report(int * r);

private:
    int n; // size
    int bins; // number of segements
    int max_integer_value;
    struct node {
        int value;
        node * next;
        node(int v, node * n){
            value = v;
            next = n;
        }
    };
    node ** bin;
    node * sentinal;
    
    node * rinsert(node * parent, int t){
        if(parent->value < t){
            parent->next = rinsert(parent->next, t);
        } else if(parent->value > t){
            parent = new node(t, parent);
            n++;
        }
        return parent;
    }


};

#endif	/* _INTEGERBITBINSEARCHER_H */

