#pragma once
#include <string>
#include <map>
#include "MyExceptions.h"
#include "IOperatorMaker.h"

using namespace std;

class Factory{
    map<string, IOperatorMaker*> operations_;
private:
    Factory() = default;
public:
    Factory& operator=(const Factory&) = delete;
    Factory(const Factory&) = delete;
    static Factory& getInstance();
    void addOperatorMaker(const string& str, IOperatorMaker * operatorMaker);
    IOperatorMaker& getOperatorMaker(const string& str);
};