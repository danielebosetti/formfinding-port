#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class fileLoader;

// "NdFreedom"

class Restraint
{
public:

	long IDFreedomCase;
	long nodeID;
	long coordSysID;

	std::vector<std::string> components;
	std::map<std::string, double> imposedDisplacements;

	Restraint(void);
	~Restraint(void);

	Restraint(const Restraint&);


	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

