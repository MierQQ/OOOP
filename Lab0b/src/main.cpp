#include "Analyzer.h"
#include <iostream>

int  main(int argc, char* argv[]){
	if (argc > 1) {
		Analyzer analyzer;
		try {
			for (int i = 1; i < argc - 1; ++i) {
				analyzer.AddFile(argv[i]);
			}
			analyzer.OutCSV(argv[argc - 1]);
		}
		catch (const char* exeption) {
			std::cout << "Error: " << exeption << std::endl;
		}
	}
	else {
		std::cerr << "No arguments" << std::endl;
	}
}