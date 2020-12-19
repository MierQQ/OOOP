#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include "MyExceptions.h"
#include "OperatorMaker.h"

using namespace std;

class Calculator {
    list<double> stack_;
    map<string, double> variables_;
    ifstream* input_;
    ofstream* output_;
public:
    Calculator();
    Calculator(const string& in, const string& out);
    void calculate();
    ~Calculator();
};

