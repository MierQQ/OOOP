#include "MyExceptions.h"

inputError::inputError(const char* str) : MyException(str) {}

wrongArgs::wrongArgs() : inputError("Wrong arguments") {}

wrongArgs::wrongArgs(const char* str) : inputError(str) {}

excessArgs::excessArgs() : wrongArgs("Excess elements in arguments") {}

lackOfArgs::lackOfArgs() : wrongArgs("Lack of args") {}

divisionByZero::divisionByZero() : wrongArgs("Division by zero"){}

stackError::stackError() : MyException("Stack error") {}

stackError::stackError(const char* str) : MyException(str) {}

MyException::MyException() : exception("Something happened wrong") {}

MyException::MyException(const char* str) : exception(str) {}

void MyException::setLine(int line)
{
	line_ = line;
}

int MyException::getLine() const
{
	return line_;
}

operatorError::operatorError() : inputError("No such operator") {}
