#pragma once
#include "IOperator.h"
#include <string>

class IOperatorMaker {
public:
	virtual IOperator* create() = 0;
};

