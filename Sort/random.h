
/*
 * File:   random.h
 * Author: mark
 *
 * Created on 17 September 2010, 8:35 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef _RANDOM_H
#define	_RANDOM_H

char * randomString(int string_sz);
char randomChar();
int randomInteger(int low, int high);

#endif	/* _RANDOM_H */

