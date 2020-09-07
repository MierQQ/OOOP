#include "Analyzer.h"
#include <iostream>

int  main(int argc, char* argv[]){
	if (argc > 1) {
		Analyzer analyzer;
		for (int i = 1; i < argc - 1; ++i) {
			analyzer.AddFile(argv[i]);
		}
		analyzer.OutCSV(argv[argc - 1]);
	}
	else {
		std::cerr << "No arguments" << std::endl;
	}
<<<<<<< HEAD
}
=======
}
>>>>>>> da5efd06bae83f7d16b2ab912ebe465a874fe85a
