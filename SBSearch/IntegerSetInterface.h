/* 
 * File:   IntegerSetInterface.h
 * Author: mark
 *
 * Created on 13 August 2010, 6:47 PM
 */

#ifndef _INTEGERSETINTERFACE_H
#define	_INTEGERSETINTERFACE_H

class IntegerSetInterface {
public:
    IntegerSetInterface(int max_nr_elements, int max_integer_value);
    IntegerSetInterface(const IntegerSetInterface& orig);
    virtual ~IntegerSetInterface();

    void insert(int t);
    int size();
    void report(int * v);

private:
    int n; // number of elements in array

    struct node {
        int val;
        node * next;
        node(int v, node *p){
            val = v;
            next = p;
        }
    };
    node * head;
    node * sentinal;
    node * rinsert(node * p, int t){
        if(p->val < t){
            p->next = rinsert(p->next, t);
        } else if(p->val > t) {
            p = new node(t, p);
            n++;
        }
        return p;
    }
};

#endif	/* _INTEGERSETINTERFACE_H */

