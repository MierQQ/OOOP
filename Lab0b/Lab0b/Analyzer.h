#pragma once
#include <string>
#include <map>
#include <iostream>
#include <list>
using std::string;
using std::map;
using std::list;



class Analyzer {
	map<string, int> wordMap;
	int counter;
	int IsLetterOrNumber(char);
public:
	void AddFile(string);
	void OutCSV(string);
	Analyzer();

};