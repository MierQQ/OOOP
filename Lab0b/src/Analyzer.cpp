#include "Analyzer.h"
#include <string>
#include <fstream>
#include <map>

Analyzer::Analyzer() {
	counter = 0;
}

int IsLetterOrNumber(char ch) {
	return	(ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			(ch >= '0' && ch <= '9');
}
using namespace std;

void Analyzer::AddFile(string inputFile) {
	ifstream input;
	input.open(inputFile);
	if (!input.is_open()) {
		throw ("failed to open input file");
	}
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
	multimap<int, string> sortedMap;
	for (auto mapIterator = wordMap.rbegin(); mapIterator != wordMap.rend(); ++mapIterator) {
		sortedMap.insert(pair<int, string>(mapIterator->second, mapIterator->first));
	}
	wordMap.clear();
	ofstream output;
	output.open(outputFile);
	if (!output.is_open()) {
		throw ("failed to open output file");
	}
	for (auto multimapIterator = sortedMap.rbegin(); multimapIterator != sortedMap.rend(); ++multimapIterator) {
		output << multimapIterator->second << ',' << multimapIterator->first << ',' << multimapIterator->first / (double)counter * 100 << '%' << endl;
	}
	counter = 0;
	output.close();
}