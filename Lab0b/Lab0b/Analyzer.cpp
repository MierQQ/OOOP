#include "Analyzer.h"
#include <string>
#include <fstream>
#include <map>

Analyzer::Analyzer() {
	counter = 0;
}

int Analyzer::IsLetterOrNumber(char ch) {
	return	(ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			(ch >= '0' && ch <= '9');
}
using namespace std;

void Analyzer::AddFile(string inputFile) {
	ifstream input;
	input.open(inputFile);
	while (!input.eof()) {
		string line;
		getline(input, line);
		string word;
		for (unsigned int i = 0; i <= line.length(); ++i) {
			if (i != line.length() && IsLetterOrNumber(line[i])) {
				word += line[i];
			}
			else if (word.length() > 0) {
				++counter;
				wordMap[word] += 1;
				word.clear();
			}
		}
	}
	input.close();
}

void Analyzer::OutCSV(string outputFile) {
	ofstream output;
	output.open(outputFile);
	for (map<string, int>::iterator slidingPair = wordMap.begin(); slidingPair != wordMap.end(); ++slidingPair) {
		output << slidingPair->first << ',' << slidingPair->second << ',' << ((double)slidingPair->second / counter) * 100 << '%' << endl;
	}
	output.close();
}