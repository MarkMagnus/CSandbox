/* 
 * File:   main.c
 * Author: mark
 *
 * Created on 24 September 2010, 9:52 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "fileUtil.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char * fileName = "text.txt";

    //write file line by line
    WFILE * wfile = openWFile(fileName);
    int i;
    char line[100];
    for(i = 0; i < 100; i++){
        sprintf(line, "hello %d", i);
        appendLineToWFile(wfile, line);
    }
    closeWFile(wfile);

    //read whole file
/*
    RFILE * rfile = openRFile(fileName);
    char * text = readAllFromRFile(rfile);
    printf("%s", text);
    closeRFile(rfile);
*/

    //read file line by line
    RFILE * rfile = openRFile(fileName);
    char * text;
    int position = 0;
    int * ptr_position = &position;

/*
    int eof = readLineFromRFile(rfile, &text, &ptr_position);
    printf("eof: %d pos: %d line: %s \n" , eof, *ptr_position, text);

    eof = readLineFromRFile(rfile, &text, &ptr_position);
    printf("eof: %d pos: %d line: %s \n" , eof, *ptr_position, text);
*/

    while(readLineFromRFile(rfile, &text, &ptr_position) == 0){
        printf("pos: %d line: %s \n" , *ptr_position, text);
    }


/*
    int integer = 100;
    int * ptr_integer = &integer;
    printf("%d\n", *ptr_integer);
    setIntegerToTen(&ptr_integer);
    printf("%d\n", *ptr_integer);
*/
  


   
    closeRFile(rfile);

    // delete file
    deleteFile(fileName);

    return (EXIT_SUCCESS);
}

