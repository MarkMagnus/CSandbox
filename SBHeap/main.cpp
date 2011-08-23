/* 
 * File:   main.cpp
 * Author: mark
 *
 * Created on 10 August 2010, 6:55 PM
 */

#include <stdlib.h>
#include <stdio.h>

#include "PriorityQueue.cpp"

int main(int argc, char** argv) {

    int n = 10;

    PriorityQueue<int> queue(n);

    queue.insert(19);
    queue.insert(1);
    queue.insert(5);
    queue.insert(6);
    queue.insert(9);
    queue.insert(7);
    queue.insert(4);
    queue.insert(100);
    queue.insert(101);
    queue.insert(12);

    for(int i = 0; i < n; i++){
        printf("%d\n", queue.extractMinimum());
    }



   return (EXIT_SUCCESS);
}

