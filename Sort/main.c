/* 
 * File:   main.c
 * Author: mark
 *
 * Created on 24 September 2010, 7:34 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "random.h"
#include "listgen.h"
#include "fileUtil.h"
#include "sort.h"

int main(int argc, char** argv) {


    int size = 50;
    int high = 1000;
    int low = 0;
    int * integers = generateRandomIntegerList(size, low, high);

    char * sourceFile = "sortSourceFile.txt";

    WFILE * wfile = openWFile(sourceFile);
    char line[50];
    int i;
    for(i = 0; i < size; i++){
        sprintf(line, "%d", integers[i]);
        appendLineToWFile(wfile, line);
    }
    closeWFile(wfile);

    char * storeFile = "sortStoreFile.txt";
    
    int * ptr_size = &size;
    sortIntegers(&integers, &ptr_size);
    size = *ptr_size;

    wfile = openWFile(storeFile);
    int j;
    int integer;
    for(j = 0; j < size; j++){
        integer = integers[j];
        sprintf(line, "%d", integer);
        appendLineToWFile(wfile, line);
    }
    closeWFile(wfile);

    // tidy
    deleteFile(sourceFile);



/*
    printf("Bit Mask Test");
    int i;
    for(i = 0; i < 50; i++){
        printf("%d\n", bitMask32(i));
    }


    printf("Shift Test");
    int j;
    for(j = 0; j < 50; j++){
        printf("%d-%d\n", j, shift(j*32));
    }
*/




    return (EXIT_SUCCESS);
}

