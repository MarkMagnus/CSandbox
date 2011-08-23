/* 
 * File:   IntegerBitSearcher.h
 * Author: mark
 *
 * Created on 17 August 2010, 10:04 PM
 */

#ifndef _INTEGERBITSEARCHER_H
#define	_INTEGERBITSEARCHER_H

class IntegerBitSearcher {
public:
    IntegerBitSearcher(int max_nr_integers, int max_value_integer);
    IntegerBitSearcher(const IntegerBitSearcher& orig);
    virtual ~IntegerBitSearcher();

    void insert(int i);
    void report(int * r);

    // determines which bin of 32bits the integer
    // belongs to by effectively dividing by 32
    // but in a more efficient manor
    int bit_map_shift(int i){
        return i>>SHIFT;
        //return i / 32;
    }

    // determine which bit of the 32 integer value
    // this number corresponds to
    // bitwise boolean operation with the mask destroys
    // all integer information above 32bits
    // then a shift which applies an effective exponential of 2 to the
    // power
    int bit_map_mask(int i){
        return 1 << bit_wise(i);
    }

    int bit_wise(int i){
        return i & MASK;
    }

    // |= 
    void set_bit_map_at(int i){
        container[bit_map_shift(i)] |= (bit_map_mask(i));
    }

    void clear_bit_map_at(int i){
        container[bit_map_shift(i)] &= ~(bit_map_mask(i));
    }

    int test_bit_map_for(int i){
        return container[bit_map_shift(i)] & (bit_map_mask(i));
    }

private:
    enum {
        BITSPERWORD = 32,
        SHIFT = 5,
        MASK = 0x1F
    };

    int n; // size
    int highest_value;
    int * container;

};

#endif	/* _INTEGERBITSEARCHER_H */

