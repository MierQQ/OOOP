#include <iostream>
#include "module1.h"
#include "module2.h"
#include "module3.h"

int main() {
	std::cout << "Hello world" << std::endl;
	std::cout << Module1::GetMyName() << std::endl;
	std::cout << Module2::GetMyName() << std::endl;
	
	using namespace Module1;
	std::cout << GetMyName() << std::endl;// John
	std::cout << Module2::GetMyName() << std::endl;

	//using namespace Module2;                          // будет перегрузка с одинаковыми аргуметрами
	//std::cout << GetMyName() << std::endl;            // устанить можно using Module2::GetMyName;

	using Module2::GetMyName;
	std::cout << GetMyName() << std::endl;// James
	
	std::cout << Module3::GetMyName() << std::endl;
	// можно написать using std::cout;
	using std::cout;
	cout << Module3::GetMyName();
}