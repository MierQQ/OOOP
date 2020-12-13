#pragma once
#include <exception>

using namespace std;

class MyException : public exception {
	int line_ = 0;
public:
	MyException();
	MyException(const char* str);
	void setLine(int line);
	int getLine() const;
};

class inputError : public MyException {
public:
	inputError(const char* str);
};

class wrongArgs : public inputError {
public:
	wrongArgs();
	wrongArgs(const char* str);
};

class excessArgs : public wrongArgs {
public:
	excessArgs();
};

class lackOfArgs : public wrongArgs {
public:
	lackOfArgs();
};

class divisionByZero : public wrongArgs {
public:
	divisionByZero();
};

class stackError : public MyException {
public:
	stackError();
	stackError(const char* str);
};

class operatorError : public inputError {
public:
	operatorError();
};