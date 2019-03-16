#pragma once
#include <iostream>
#include <string>

class fileLoader;

// "PlGlobalLoad"

class PlGlobalLoad
{
public:
	long loadCaseID, plateID;
	double qx, qy, qz;
	std::string projectedComp;

	PlGlobalLoad(void);
	~PlGlobalLoad(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

