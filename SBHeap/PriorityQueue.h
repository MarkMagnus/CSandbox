/* 
 * File:   PriorityQueue.h
 * Author: mark
 *
 * Created on 12 August 2010, 3:42 PM
 */

#ifndef _PRIORITYQUEUE_H
#define	_PRIORITYQUEUE_H

template<typename T>
class PriorityQueue {
public:
    PriorityQueue(int m);
    virtual ~PriorityQueue();
    void insert(T t);
    T extractMinimum();
    
private:
    int n; // number of elements in heap
    int max_size; // maximum number of elements in heap
    T * x; // the heap
    
    void swap(int i, int j);

    T value(int i){
        return x[i];
    }

    T leftchild(int i){
        return x[2 * i];
    }

    T rightchild(int i){
        return x[2 * i + 1];
    }

    T parent(int i){
        return x[i / 2];
    }

    

};

#endif	/* _PRIORITYQUEUE_H */

