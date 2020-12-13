#include "Calculator.h"

using namespace std;

int main(int argv, char** args) {
	try {
		if (argv > 2) {
			Calculator calc(args[1], args[2]);
			calc.calculate();
		}
		else {
			Calculator calc;
			calc.calculate();
		}
	}
	catch (exception & exception) {
		cout << exception.what();
	}
}
