/* 
 * File:   unwrapJson.h
 * Author: mark
 *
 * Created on 13 September 2010, 11:09 AM
 */
extern "C" {
    #include "jsonToMap.h"
}

#include <json/json.h>
#include <gtest/gtest.h>

#ifndef _UNWRAPJSON_H
#define	_UNWRAPJSON_H

TEST(JsonTest, Unwrap){

    char * json = "{ \"name\":\"Joe\", \"age\":42 }";
    char ** keys;
    char ** values;
    json_type * types;
    
    int size = mapJson(json, keys, values, types);

    ASSERT_EQ(2, size);


    for(int i = 0; i < size; i++){
        printf("k:%s v:%s t:%d\n", keys[i], values[i], types[i]);
    }
    
//    JsonRecord * record = new JsonRecord("{ \"name\" : \"Joe\" }");
//    json_type type = record->getType("name");
//    char * value = (char *) record->getValue("name");
//
//    ASSERT_EQ(json_type_string, type);
//    ASSERT_EQ("Joe", value);
}


#endif	/* _UNWRAPJSON_H */

