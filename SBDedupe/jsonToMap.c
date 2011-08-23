#include <stdio.h>
#include <stdlib.h>
#include <json/json.h>
#include <string.h>

#include "jsonToMap.h"

int mapJson(char * json, char ** keys, char ** values, json_type * types){

    struct json_object * jobject;
    jobject = json_tokener_parse(json);
    struct json_object * jnameobject;

    struct lh_entry * entry;
    char * key;
    struct json_object * val;

    int count = 0;
    
    
    
    for(entry = json_object_get_object(jobject)->head;
       (entry ? (key = (char*)entry->k, val = (struct json_object*)entry->v, entry) : 0);
       entry = entry->next) {

        // key
        printf("key: %s \n", key);

        //struct json_object * o = json_object_object_get(jobject, key);
        json_type type = json_object_get_type(val);

        // type
        char * json_type_name = jsonTypeToString(type);
        printf("type: %s\n", json_type_name);
        
        char * value = (char *) malloc(sizeof(char)*256 + 1);
        int i = 0;
        // value
        switch(type){
            case json_type_null:
                break;
            case json_type_boolean:
                break;
            case json_type_double:
                break;
            case json_type_int:
                sprintf(value, "%d", json_object_get_int(val));
                break;
            case json_type_object:
                break;
            case json_type_array:
                
                break;
            case json_type_string:
                value = json_object_to_json_string(val);
                break;

        }
        printf("value: %s\n", value);

        count++;
    }
    return count;
}



char * jsonTypeToString(json_type type){

    char * type_name =  (char *) malloc(sizeof(char)*10);
    switch(type){
        case json_type_null:
            type_name =  "null";
            break;
        case json_type_boolean:
            type_name ="boolean";
            break;
        case json_type_double:
            type_name ="double";            
            break;
        case json_type_int:
            type_name ="integer";            
            break;
        case json_type_object:
            type_name ="object";            
            break;
        case json_type_array:
            type_name ="array";            
            break;
        case json_type_string:
            type_name ="string";            
            break;
        default:
            type_name = "";
    }

    return type_name;
}

