#pragma once
#include <iostream>
#include <string>
#include <vector>

class fileLoader;

// "PlPatchType"

class PlPatchType
{
public:
	long ID;
	long boh1;
	long type;
	std::vector<double> values;

	PlPatchType(void);
	~PlPatchType(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

