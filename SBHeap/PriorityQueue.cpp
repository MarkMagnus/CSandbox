/* 
 * File:   PriorityQueue.cpp
 * Author: mark
 * 
 * Created on 12 August 2010, 3:42 PM
 */

#include "PriorityQueue.h"

template<typename T>
PriorityQueue<T>::PriorityQueue(int m) {
    max_size = m;
    x = new T(max_size + 1);
    n = 0;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
}

template<typename T>
void PriorityQueue<T>::insert(T t){
    int i;
    int parent;
    x[++n] = t; // insert into the heap
    // then shift up the newly insert value as required
    for(i = n; i > 1 && x[parent=i/2] > x[i]; i = parent){
        swap(parent, i);
    }
}

template<typename T>
T PriorityQueue<T>::extractMinimum(){
    int i;
    int child;
    T t = x[1]; // minimum top of the heap;
    x[1] = x[n--]; // assign the first value to the last value
    // shift down last value
    for(i = 1; (child = 2 * i) <= n; i = child ){
        if (child + 1 <= n && x[child + 1] < x[child]){
            child++;
        }
        if (x[i] <= x[child]){
            break;
        }
        swap(child, i);
    }
    return t;
}

template<typename T>
void PriorityQueue<T>::swap(int i, int j){
    T t = x[i];
    x[i] = x[j];
    x[j] = t;
}
