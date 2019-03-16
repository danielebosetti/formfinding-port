#pragma once

// "LoadCase"

#include <iostream>
#include <string>

class fileLoader;

class LoadPattern
{
public:

	long ID, boh1;
	std::string name;

	long numGravity;
	double gravity;
	std::vector<char*> otherProperties;

	// true if it is part of LCCFF
	bool selectedForFF;
	// only set if this is part of LCCFF
	double alphaCoefficient;
	// alpha parameter set by user
	double alpha_User;

	LoadPattern(void);
	~LoadPattern(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

