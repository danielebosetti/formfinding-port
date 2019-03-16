#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "LoadCaseCombinationItem.h"

class fileLoader;

class LoadCaseCombination
{
public:
	long ID;
	std::string name;
	std::vector<long> loadPatternID;
	std::vector<long> freedomCaseID;
	std::vector<double> loadMultiplierAlpha;

	std::vector<loadCaseCombinationItem> components;


	// lines to output...
	std::vector<char*> properties;

	LoadCaseCombination(void);
	~LoadCaseCombination(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

