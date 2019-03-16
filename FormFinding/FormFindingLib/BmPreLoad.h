#pragma once

#include <iostream>
#include <string>

class fileLoader;

class BmPreLoad
{
public:
	long loadCaseID, beamID, boh1;
	double P0;
	std::string tensionStrain;

	BmPreLoad(void);
	~BmPreLoad(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

