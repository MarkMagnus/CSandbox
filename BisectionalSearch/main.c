/* 
 * File:   main.c
 * Author: mark
 *
 * Created on 28 September 2010, 6:39 PM
 */

#include <stdio.h>
#include <stdlib.h>


int find(int * haystack, size_t size, int needle){
    
    int upper = size - 1;
    int lower = 0;
    int middle = 0;

    for(;;){

        if (haystack[size - 1] == needle){
            return size - 1;
        }

        if(middle != ((upper + lower) / 2)) {
           middle = (upper + lower) / 2;
        } else {
            return -1;
        }

        int value = haystack[middle];

        if(value < needle){
            lower = middle;
        } else if(value > needle){
            upper = middle;
        } else if(value == needle){
            return middle;
        } 
        
        

    } // loop till return

}


int main(int argc, char** argv) {

    size_t size = 11;
    int array[11] = {1,2,4,5,6,8,9,23,45,345,781};

    int i;
    for(i = 0; i < size; i++){
        printf("%d - %d\n", i, array[i]);
    }


    printf("%d\n", find(array, size, 1));
    printf("%d\n", find(array, size, 2));
    printf("%d\n", find(array, size, 4));
    printf("%d\n", find(array, size, 5));
    printf("%d\n", find(array, size, 6));
    printf("%d\n", find(array, size, 8));
    printf("%d\n", find(array, size, 9));
    printf("%d\n", find(array, size, 23));
    printf("%d\n", find(array, size, 45));
    printf("%d\n", find(array, size, 345));
    printf("%d\n", find(array, size, 781));
 

    printf("%d\n", find(array, size, 13));
    return (EXIT_SUCCESS);
}

