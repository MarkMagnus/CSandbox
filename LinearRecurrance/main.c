/* 
 * File:   main.c
 * Author: mark
 *
 * Created on 2 November 2010, 9:49 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "fibonacci.h"
#include "recurrence.h"

void testFibonacciSeriesFns(){
    int i;
    int n = 100;
    for(i = 0; i < n; i++){
        //printf("%d == %d\n", fib(i), fast_fib(i));
        printf("%d - %d\n", i, fast_fib(i));
    }
}

void testRecurranceFns(){

    int k = 4;
    int sz = k + 1;
    int c[5] = {1,2,2,1,3};
    int m = 3;

}

int main(int argc, char** argv) {

    //testFibonacciSeriesFns();
    testRecurranceFns();

    return (EXIT_SUCCESS);
}

