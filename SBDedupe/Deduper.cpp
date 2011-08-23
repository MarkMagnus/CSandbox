/* 
 * File:   Deduper.cpp
 * Author: mark
 * 
 * Created on 19 August 2010, 10:15 PM
 */

#include "Deduper.h"
#include <string.h>

Deduper::Deduper() {
    n = 0;
    sentinal = new word("EOF", 0);
    root = new word("BOF", sentinal);
}

Deduper::Deduper(const Deduper& orig) {
}

Deduper::~Deduper() {

}

int Deduper::insert(char * w){

    if(test(w) == 1){
        return 0;
    } else {
        for(word * i = root;  ; i = i->next){
            if(i->next == sentinal){
                word * t = new word(w, sentinal);
                i->next = t;
                n++;
                break;
            }
        }
    }
    return n;
}

void Deduper::report(char ** r){
   //char ** report;

   int j = 0;
   for(word * i = root->next; i != sentinal; i = i->next){
       //report[j++] = i->value;
       r[j++] = i->value;
   }
   //r = report;
}

int Deduper::same(char * a, char * b){
    return strcmp(a, b) == 0;
}

int Deduper::size(){
    return n;
}

int Deduper::test(char* w){
    for(word * i = root->next; ; i = i->next){
        if(same(i->value, w) == 1){
            return 1;
        }
        if(i == sentinal){
            break;
        }
    }
    return 0;
}

