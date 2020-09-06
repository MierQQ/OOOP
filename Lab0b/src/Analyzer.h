#pragma once
#include <string>
#include <map>
#include <iostream>

using std::string;
using std::map;

class Analyzer {
	map<string, int> wordMap;
	int counter;
	int IsLetterOrNumber(char);

public:
	void AddFile(string);
	void OutCSV(string);
	Analyzer();

};