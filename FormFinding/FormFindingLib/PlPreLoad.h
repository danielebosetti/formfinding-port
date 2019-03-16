#pragma once

#include <iostream>
#include <string>

class fileLoader;

class PlPreLoad
{
public:
	long loadCaseID, plateID, boh1;

	double px, py, pz;
	std::string stressStrain;
	bool is_STRESS;

	PlPreLoad(void);
	~PlPreLoad(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

