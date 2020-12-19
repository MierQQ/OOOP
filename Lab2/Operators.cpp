#include "Operators.h"

using namespace std;

namespace {
	OperatorMaker<Pop> pop("POP");
	OperatorMaker<Push> push("PUSH");
	OperatorMaker<Plus> plus("+");
	OperatorMaker<Minus> minus("-");
	OperatorMaker<Mul> mul("*");
	OperatorMaker<Div> dic("/");
	OperatorMaker<Sqrt> SQRT("SQRT");
	OperatorMaker<Print> print("PRINT");
	OperatorMaker<Define> define("DEFINE");
}

void Pop::calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out) {
	if (args.size() > 0) {
		throw excessArgs();
	}
	if (stack.size() == 0) {
		throw stackError("Stack is empty");
	}
	stack.pop_front();
}

void Push::calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out) {
	if (args.size() > 1) {
		throw excessArgs();
	}
	if (args.size() < 1) {
		throw lackOfArgs();
	}
	double value;
	if (variables.find(args.front()) != variables.end()) {
		value = variables[args.front()];
	}
	else try{
		size_t size = 0;
		value = stod(args.front(), &size);
		if (size != args.front().size()) {
			throw exception();
		}
	}
	catch(exception) {
		throw wrongArgs();
	}
	stack.push_front(value);
}

void Plus::calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out){
	if (args.size() > 0) {
		throw excessArgs();
	}
	double value = 0;
	if (stack.size() < 2) {
		throw lackOfArgs();
	}
	value += stack.front();
	stack.pop_front();
	value += stack.front();
	stack.pop_front();
	stack.push_front(value);
}

void Minus::calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out) {
	if (args.size() > 0) {
		throw excessArgs();
	}
	double value = 0;
	if (stack.size() < 2) {
		throw lackOfArgs();
	}
	value += stack.front();
	stack.pop_front();
	value -= stack.front();
	stack.pop_front();
	stack.push_front(value);
}

void Mul::calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out) {
	if (args.size() > 0) {
		throw excessArgs();
	}
	double value = 0;
	if (stack.size() < 2) {
		throw lackOfArgs();
	}
	value += stack.front();
	stack.pop_front();
	value *= stack.front();
	stack.pop_front();
	stack.push_front(value);
}

void Div::calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out) {
	if (args.size() > 0) {
		throw excessArgs();
	}
	double value = 0;
	if (stack.size() < 2) {
		throw lackOfArgs();
	}
	value += stack.front();
	stack.pop_front();
	if (stack.front() != 0) {
		value /= stack.front();
	}
	else {
		throw divisionByZero();
	}
	stack.pop_front();
	stack.push_front(value);
}

void Sqrt::calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out) {
	if (args.size() > 0) {
		throw excessArgs();
	}
	double value = 0;
	if (stack.size() < 1) {
		throw lackOfArgs();
	}
	value += stack.front();
	stack.pop_front();
	value = sqrt(value);
	stack.push_front(value);
}

void Print::calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out) {
	if (args.size() > 0) {
		throw excessArgs();
	}
	double value = 0;
	if (stack.size() < 1) {
		throw lackOfArgs();
	}
	value += stack.front();
	if (out != nullptr) {
		*out << value << endl;
	}
	else {
		cout << value << endl;
	}
}

void Define::calculate(list<string> args, list<double>& stack, map<string, double>& variables, ofstream* out){
	if (args.size() > 2) {
		throw excessArgs();
	}
	if (args.size() < 2) {
		throw lackOfArgs();
	}
	string str = args.front();
	args.pop_front();
	try {
		size_t size = 0;
		variables[str] = stod(args.front(), &size);
		if (size != args.front().size()) {
			throw exception();
		}
		args.pop_front();
	}
	catch(exception) {
		throw wrongArgs();
	}
}

