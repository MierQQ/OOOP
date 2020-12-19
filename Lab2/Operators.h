#pragma once
#include <list>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "MyExceptions.h"
#include "IOperator.h"
#include "OperatorMaker.h"

using namespace std;

class Pop : public IOperator {
public:
    void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out);
};

class Push : public IOperator {
public:
    void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out);
};

class Plus : public IOperator {
public:
    void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out);
};

class Minus : public IOperator {
public:
    void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out);
};

class Mul : public IOperator {
public:
    void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out);
};

class Div : public IOperator {
public:
    void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out);
};

class Sqrt : public IOperator {
public:
    void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out);
};

class Print : public IOperator {
public:
    void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out);
};

class Define : public IOperator {
public:
    void calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out);
};


