#pragma once
#include <string>
#include <map>
#include "MyExceptions.h"
#include "Operators.h"

using namespace std;

class Factory{
    map<string, IOperator*> operations_;
private:
    Factory();
public:
    static Factory& getInstance();
    void addOperator(const string& str, IOperator* op);
    IOperator& createOperator(const string& str);
};