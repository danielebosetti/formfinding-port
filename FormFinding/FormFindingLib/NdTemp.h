#pragma once


#include <iostream>
#include <string>

class fileLoader;

class NdTemp
{
public:
	long loadCaseID, nodeID, boh1;
	std::string type;
	double temperature;

	NdTemp(void);
	~NdTemp(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

