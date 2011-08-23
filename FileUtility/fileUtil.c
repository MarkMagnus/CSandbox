#include <stdio.h>
#include <stdlib.h>
#include "fileUtil.h"


WFILE * openWFile(char * fileName){
    FILE * file = fopen(fileName,"w");
    return (WFILE *) file;
}

int appendLineToWFile(WFILE * file, char * text){
    if(file != NULL){
        fprintf((FILE *)file,"%s\n", text);
        return 1;
    } else {
        return 0;
    }
}

int appendToWFile(WFILE * file, char * text){
    if(file != NULL){
        fprintf((FILE *)file,"%s", text);
        return 1;
    } else {
        return 0;
    }
}

int closeWFile(WFILE * file){
    if(file != NULL){
        fclose((FILE *)file);
        return 1;
    } else {
        return 0;
    }
}

int deleteFile(char * fileName){
    if (remove(fileName) == -1){
        perror("Error in deleting a file");
        return 0;
    } else {
        return 1;
    }
}

 RFILE * openRFile(char * fileName){
    FILE * file = fopen(fileName,"r");
    return (RFILE *) file;
 }

 char * readAllFromRFile(RFILE * file) {


    int buffer_sz = 256;
    char * buffer = (char *)malloc(sizeof(char)*buffer_sz + 1); // +1 EOF /0

    char c = getc((FILE * ) file); // initialize

    int i = 0;
    while (c!= EOF) {

        // check buffer size
        if(buffer_sz == i + 1){
            buffer_sz = buffer_sz * 2; // double buffer
            buffer = (char *)realloc(buffer, sizeof(char)*buffer_sz + 1);
        }

        buffer[i] = c;

        i++;
        c = getc((FILE * ) file);

    }
    buffer[i] = '\0';

    return buffer;
 }

 int readLineFromRFile(RFILE * file, char ** text, int ** position){

    int buffer_sz = 256;
    char * buffer = (char *)malloc(sizeof(char)*buffer_sz + 1); // +1 EOF /0

    int current_position = **position;

    printf("start read from position: %d\n", current_position);

    // more to selected position
    rewind((FILE *) file);
    fseek ((FILE *) file, current_position, SEEK_CUR);

    char c = getc((FILE * ) file); // initialize

    int i = 0;
    for (;;) {

        // check buffer size
        if(buffer_sz == i + 1){
            buffer_sz = buffer_sz * 2; // double buffer
            buffer = (char *)realloc(buffer, sizeof(char)*buffer_sz + 1);
        }
        
        buffer[i] = c;

        // end of line
        if(c == '\n') {
            buffer[i] = '\0';
            *text = buffer;
            current_position++;
            *position = &current_position;
            return 0;
        }

        // end of file
        if(c == EOF) {
            buffer[i] = '\0';
            *text = buffer;
            *position = &current_position;
            return 1;
        }

        c = getc((FILE * ) file);
        i++;
        current_position++;
        printf("c: %d", current_position);

    }

 }

 int closeRFile(RFILE * file){
     if(file != NULL){
        fclose((FILE *)file);
        return 1;
    } else {
        return 0;
    }
 }

void setIntegerToTen(int ** integer){
    int newInteger = 10;
    *integer = &newInteger;
}