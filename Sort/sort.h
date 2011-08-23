/* 
 * File:   sort.h
 * Author: mark
 *
 * Created on 25 September 2010, 11:28 AM
 */

#ifndef _SORT_H
#define	_SORT_H

#ifdef	__cplusplus
extern "C" {
#endif

    #define BITMAP_SIZE 10000000
    #define BITMAP_SHIFT 5
    #define BITMAP_MASK 0x1F
    #define BITMAP_WORD 32

    int BITMAP[BITMAP_SIZE/BITMAP_WORD + 1];
    
    int bitMask32(int integer);
    int shift(int integer);
    void add(int integer);
    int test(int integer);
    void clear(int integer);
    void sortIntegers(int ** integers, int ** size);

#ifdef	__cplusplus
}
#endif

#endif	/* _SORT_H */

