/* 
 * File:   main.cpp
 * Author: mark
 *
 * Created on 19 August
 *  2010, 9:13 PM
 */

#include <stdlib.h>
#include <stdio.h>

extern "C" {
    #include "jsonToMap.h"
}

#include <gtest/gtest.h>
#include "insertIntoDeduper.h"
#include "unwrapJson.h"

int main(int argc, char** argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

