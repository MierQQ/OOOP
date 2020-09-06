#include "Analyzer.h"

int main() {
	Analyzer analyzer;
	analyzer.AddFile("input.txt");
	analyzer.AddFile("input2.txt");
	analyzer.OutCSV("output.csv");
}