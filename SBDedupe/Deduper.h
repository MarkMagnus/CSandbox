/* 
 * File:   Deduper.h
 * Author: mark
 *
 * Created on 19 August 2010, 10:15 PM
 */

#ifndef _DEDUPER_H
#define	_DEDUPER_H

class Deduper {
public:
    Deduper();
    Deduper(const Deduper& orig);
    virtual ~Deduper();

    int insert(char * w);

    void report(char ** r);
    int test(char * w);
    int same(char * a, char * b);
    int size();

private:

    struct word {
        char * value;
        word * next;
        int count;
        word(char * v, word * n){
            count = 0;
            value = v;
            next = n;
        }
    };

    word * root;
    word * sentinal;
    int maximum_size;
    int n;
};

#endif	/* _DEDUPER_H */

