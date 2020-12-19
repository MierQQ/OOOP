#pragma once
#include "Operators.h"
#include "IOperatorMaker.h"
#include "Factory.h"
#include <string>

using namespace std;

template <class T>
class OperatorMaker : public IOperatorMaker{
public:
	IOperator* create();
	OperatorMaker(const string& str);
};

template<class T>
IOperator* OperatorMaker<T>::create()
{
	return new T();
}

template<class T>
OperatorMaker<T>::OperatorMaker(const string& str) {
	Factory::getInstance().addOperatorMaker(str, this);
}


