/* 
 * File:   main.c
 * Author: mark
 *
 * Created on 9 September 2010, 11:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <json/json.h>

/*
 * 
 */
int main(int argc, char** argv) {

    //char * filename = "json.txt";
    char * text = "{ \"name\" : \"mark\" }";
    struct json_object * jobject;
    jobject = json_tokener_parse(text);
    struct json_object * jnameobject;
    jnameobject = json_object_object_get(jobject, "name");
    //jobject = json_object_from_file (filename);

    json_type type;
    type = json_object_get_type(jnameobject);
    switch(type){
        case json_type_null:
            printf("null\n");
            break;
        case json_type_boolean:
            printf("boolean\n");
            break;
        case json_type_double:
            printf("double\n");
            break;
        case json_type_int:
            printf("integer\n");
            break;
        case json_type_object:
            printf("object\n");
            break;
        case json_type_array:
            printf("array\n");
            break;
        case json_type_string:
            printf("string\n");
            const char * value = json_object_to_json_string (jnameobject);
            printf("value: %s\n", value);
            break;
    }
    //printf("%d \n", jobject);

    return (EXIT_SUCCESS);
}

