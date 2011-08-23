/*
 * File:   fileUtil.h
 * Author: mark
 *
 * Created on 24 September 2010, 9:53 PM
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _FILEUTIL_H
#define	_FILEUTIL_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef FILE WFILE;

    WFILE * openWFile(char * fileName);
    int appendToWFile(WFILE * file, char * text);
    int appendLineToWFile(WFILE * file, char * text);
    int closeWFile(WFILE * file);

    typedef FILE RFILE;

    RFILE * openRFile(char * fileName);
    char * readAllFromRFile(RFILE * file);
    int readLineFromRFile(RFILE * file, char ** text, int * position);
    int closeRFile(RFILE * file);

    void setIntegerToTen(int ** integer);
    void setIntegerToFive(int * integer);

    int deleteFile(char * fileName);

#ifdef	__cplusplus
}
#endif

#endif	/* _FILEUTIL_H */

