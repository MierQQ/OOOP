#pragma once
#include <list>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class IOperator {
public:
    virtual void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out) = 0;
    virtual ~IOperator() = default;
};
