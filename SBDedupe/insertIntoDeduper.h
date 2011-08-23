///*
// * File:   insertIntoDeduper.h
// * Author: mark
// *
// * Created on 30 August 2010, 3:24 PM
// */
//
//#include <gtest/gtest.h>
//#include "Deduper.h"
//
//#ifndef _INSERTINTODEDUPER_H
//#define	_INSERTINTODEDUPER_H
//
//TEST(DeduperTests, Report){
//
//    Deduper * deduper = new Deduper();
//    deduper->insert("Hello World");
//
//    printf("Report Size %d\n", deduper->size());
//    ASSERT_EQ(1, deduper->size());
//
//    char ** report = (char **)malloc((sizeof(char *) * deduper->size()));
//    deduper->report(report);
//    for(int i = 0; i < deduper->size(); i++){
//        printf("%d - %s\n", i, report[i]);
//    }
//
//    free(report);
//    delete deduper;
//
//}
//
//
//TEST(DeduperTests, Insert){
//
//    char * a = "{ \"name\": \"hello\" }";
//    char * b = "{ \"name\" : \"world\" }";
//    char * c = "{ \"name\" : \"hello\" }";
//    char * d = "{ 'name' : 'hello'}";
//    char * e = "{'name' : 'people' }";
//    char * f = "{ 'name' : 'world' }";
//
//    Deduper * deduper = new Deduper();
//
//    int insertResult;
//    int testResult;
//
//    // insert a
//    insertResult = deduper->insert(a);
//    testResult = deduper->test(a);
//    ASSERT_EQ(1, insertResult);
//    ASSERT_EQ(1, testResult);
//    ASSERT_EQ(1, deduper->size());
//
//    // insert b
//    insertResult = deduper->insert(b);
//    testResult = deduper->test(b);
//    ASSERT_EQ(2, insertResult);
//    ASSERT_EQ(1, testResult);
//    ASSERT_EQ(2, deduper->size());
//
//    // insert c
//    insertResult = deduper->insert(c);
//    testResult = deduper->test(c);
//
//    printf("insert result %d\n", insertResult);
//    printf("test result %d\n", testResult);
//
//    ASSERT_EQ(0, insertResult);
//    ASSERT_EQ(1, testResult);
//    ASSERT_EQ(2, deduper->size());
//
//    // insert d
//    insertResult = deduper->insert(d);
//    testResult = deduper->test(d);
//    ASSERT_EQ(0, insertResult);
//    ASSERT_EQ(1, testResult);
//    ASSERT_EQ(2, deduper->size());
//
//    // insert e
//    insertResult = deduper->insert(e);
//    testResult = deduper->test(e);
//    ASSERT_EQ(3, insertResult);
//    ASSERT_EQ(1, testResult);
//    ASSERT_EQ(3, deduper->size());
//
//    // insert f
//    insertResult = deduper->insert(f);
//    testResult = deduper->test(f);
//    ASSERT_EQ(0, insertResult);
//    ASSERT_EQ(1, testResult);
//    ASSERT_EQ(3, deduper->size());
//
//    char ** report = (char **)malloc((sizeof(char *) * deduper->size()));
//    deduper->report(report);
//    for(int i = 0; i < deduper->size(); i++){
//        printf("%d - %s\n", i, report[i]);
//    }
//
//    free(report);
//    delete deduper;
//
//}
//
//
//TEST(DeduperTests, Same){
//
//    Deduper * deduper = new Deduper();
//    int test1 = deduper->same("hello", "hello");
//    int test2 = deduper->same("world", "planet");
//
//    printf("test1 %d\n", test1);
//    printf("test2 %d\n", test2);
//
//    ASSERT_EQ(1, test1);
//    ASSERT_EQ(0, test2);
//
//    delete deduper;
//
//}
//
//#endif	/* _INSERTINTODEDUPER_H */
//
