#pragma once
#include "Factory.h"

Factory& Factory::getInstance()
{
	static Factory result;
	return result;
}

void Factory::addOperatorMaker(const string& str, IOperatorMaker * operatorMaker) {
	operations_[str] = operatorMaker;
}

IOperatorMaker& Factory::getOperatorMaker(const string& str)
{
	if (operations_.find(str) != operations_.end()) {
		return *operations_[str];
	}
	else {
		throw operatorError();
	}
}
