/* 
 * File:   jsonToMap.h
 * Author: mark
 *
 * Created on 14 September 2010, 8:32 AM
 */

#include <json/json.h>

#ifndef _JSONTOMAP_H
#define	_JSONTOMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

int mapJson(char * json, char ** keys, char ** values, json_type * types);
char * jsonTypeToString(json_type type);

#ifdef	__cplusplus
}
#endif

#endif	/* _JSONTOMAP_H */