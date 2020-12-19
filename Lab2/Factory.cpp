#pragma once
#include "Factory.h"

Factory::Factory()
{
	static Push push;
	addOperator("PUSH", &push);
	static Pop pop;
	addOperator("POP", &pop);
	static Plus plus;
	addOperator("+", &plus);
	static Minus minus;
	addOperator("-", &minus);
	static Mul mul;
	addOperator("*", &mul);
	static Div div;
	addOperator("/", &div);
	static Sqrt SQRT;
	addOperator("SQRT", &SQRT);
	static Print print;
	addOperator("PRINT", &print);
	static Define define;
	addOperator("DEFINE", &define);
}

Factory& Factory::getInstance()
{
	static Factory result;
	return result;
}

void Factory::addOperator(const string& str, IOperator* op) {
	operations_[str] = op;
}

IOperator& Factory::createOperator(const string& str)
{
	if (operations_.find(str) != operations_.end()) {
		return *operations_[str];
	}
	else {
		throw operatorError();
	}
}
