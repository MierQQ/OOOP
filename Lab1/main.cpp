#define CATCH_CONFIG_MAIN
#include <iostream>
#include "LinkedList.h"
#include "catch.hpp"

using namespace std;

void fillList(LinkedList& list, int size) {
    for (int i = 0; i < size; ++i) {
        list.push_back(i);
    }
}

LinkedList testFunction1() {
    LinkedList toReturn;
    fillList(toReturn, 10);
    return toReturn;
}


TEST_CASE("LinkedList()", "[LinkedList]"){
    SECTION("Constructors") {
        SECTION("Empty") {
            LinkedList listTest;
            REQUIRE(listTest.size() == 0);
            REQUIRE(listTest.empty() == true);
        }
        SECTION("Copy constructor") {
            for (int j = 0; j < 10; ++j) {
                LinkedList listTest1;
                fillList(listTest1, j);
                LinkedList listTest2(listTest1);
                for (int i = 0; i < listTest2.size(); ++i) {
                    REQUIRE(listTest2.front() == i);
                    listTest2.pop_front();
                }
            }
        }
        SECTION("Move constructor") {
            LinkedList listTest3(testFunction1());
            for (int i = 0; i < listTest3.size(); ++i) {
                REQUIRE(listTest3.front() == i);
                listTest3.pop_front();
            }
        }
    }
    SECTION("Iterators") {
        SECTION("general detour") {
            for (int i = 0; i < 10; ++i) {
                LinkedList testList;
                fillList(testList, i);
                int j = 0;
                for (auto iterator = testList.begin(); iterator != testList.end(); ++iterator, ++j) {
                    REQUIRE(*iterator == j);
                }
            }
        }
        SECTION("Insert") {
            LinkedList testList;
            auto insertIterator = testList.begin();
            testList.insert(testList.insert(testList.insert(testList.insert(testList.insert(insertIterator,1),2),3),4),5);
            int i = 1;
            for (auto iterator = testList.begin(); iterator != testList.end(); ++iterator) {
                REQUIRE(*iterator == i++);
            }
        }
        SECTION("Erase single") {
            SECTION("Erase first") {
                for (int i = 1; i < 5; ++i) {
                    LinkedList testList;
                    fillList(testList, i);
                    testList.erase(testList.begin());
                    for (int j = 1; j < i; ++j) {
                        REQUIRE(testList.front() == j);
                        testList.pop_front();
                    }
                    REQUIRE(testList.empty() == true);
                }
            }
            SECTION("Erase middle") {
                for (int i = 2; i < 5; ++i) {
                    LinkedList testList;
                    fillList(testList, i);
                    testList.erase(++testList.begin());
                    for (int j = 0; j < i; ++j) {
                        if (j != 1) {
                            REQUIRE(testList.front() == j);
                            testList.pop_front();
                        }
                    }
                    REQUIRE(testList.empty() == true);
                }
            }
            SECTION("Erase last") {
                for (int i = 1; i < 5; ++i) {
                    LinkedList testList;
                    fillList(testList, i);
                    auto iterator = testList.begin();
                    for (int j = 0; j < i - 1; ++j) {
                        ++iterator;
                    }
                    testList.erase(iterator);
                    for (int j = 0; j < i - 1; ++j) {
                        REQUIRE(testList.front() == j);
                        testList.pop_front();
                    }
                    REQUIRE(testList.empty() == true);
                }
            }
            SECTION("Erase emtpy") {
                LinkedList testList;
                
            }
        }
        SECTION("Erase range") {
            LinkedList testList;
            fillList(testList, 10);
            auto iterator = testList.begin();
            ++++++++++iterator;
            testList.erase(testList.begin(),iterator);
            iterator = testList.begin();
            REQUIRE(*(iterator++) == 5);
            REQUIRE(*(iterator++) == 6);
            REQUIRE(*(iterator++) == 7);
            REQUIRE(*(iterator++) == 8);
            REQUIRE(*(iterator++) == 9);
        }
    }
    SECTION("Clear") {
        LinkedList testList;
        fillList(testList, 10);
        testList.clear();
        REQUIRE(testList.size() == 0);
        REQUIRE(testList.empty());
    }
    SECTION("Size") {
        LinkedList testList;
        fillList(testList, 10);
        REQUIRE(testList.size() == 10);
        testList.pop_back();
        REQUIRE(testList.size() == 9);
        testList.pop_front();
        REQUIRE(testList.size() == 8);
        testList.push_back(1);
        REQUIRE(testList.size() == 9);
        testList.push_front(1);
        REQUIRE(testList.size() == 10);
        testList.clear();
        REQUIRE(testList.size() == 0);
        testList.push_back(1);
        REQUIRE(testList.size() == 1);
        testList.push_front(1);
        REQUIRE(testList.size() == 2);
        testList.pop_back();
        REQUIRE(testList.size() == 1);
        testList.pop_front();
        REQUIRE(testList.size() == 0);
    }
}