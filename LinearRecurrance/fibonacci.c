#include "fibonacci.h"

unsigned int fib(unsigned int n)
{
    return n < 2 ? n : fib(n-1) + fib(n-2);
}

unsigned int fast_fib(unsigned int n){

    unsigned int result = 0;

    if(n == 0){
        result = 0;
    } else if(n == 1) {
        result = 1;
    } else {
        // block of memory for array
        int * numbers = (int *) malloc(sizeof(int) * n);

        int f1 = 0;
        int f2 = 1;

        numbers[f1] = 0;
        numbers[f2] = 1;

        int i;
        for(i = 2; i < n; i++){
            numbers[i] = numbers[f1] + numbers[f2];
            f1++;
            f2++;
        }

        result = numbers[f1] + numbers[f2];

        // free array
        free(numbers);
    }

    return result;
}
