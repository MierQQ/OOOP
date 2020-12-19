#include "Calculator.h"

using namespace std;

list<string> SplitString(string& str) {
	string word;
	list<string> result;
	for (auto i : str) {
		if (i != ' ' && i != '#' && i!= '\t') {
			word += i;
		}
		else if (word.size() != 0) {
			result.push_back(word);
			word.clear();
		}
		if (i == '#') {
			break;
		}
	}
	if (word.size() != 0) {
		result.push_back(word);
	}
	return result;
}

Calculator::Calculator() : input_(nullptr), output_(nullptr) {}

Calculator::Calculator(const string& in, const string& out)
{
	input_ = new ifstream(in);
	output_ = new ofstream(out);
}

void Calculator::calculate()
{
	int line = 0;
	istream* in;
	if (input_ == nullptr){
		in = &cin;
	}
	else {
		in = input_;
	}
	while (!in->eof()) {
		++line;
		string str;
		getline(*in, str);
		list<string> args = SplitString(str);
		if (args.size() == 0) {
			continue;
		}
		Factory& factory = Factory::getInstance();
		try {
			IOperator& oper = factory.createOperator(args.front());
			args.pop_front();
			oper.calculate(args, stack_, variables_, output_);
		}
		catch (MyException & ex) {
			cerr << "Error in line " << line << ": " << ex.what() << endl;
			ex.setLine(line);
			throw;
		}
	}
}

Calculator::~Calculator()
{
	if (input_ != nullptr && output_ != nullptr) {
		input_->close();
		output_->close();
		delete input_;
		delete output_;
	}
}

