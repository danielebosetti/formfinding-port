#pragma once


// "NdForce"

#include <iostream>
#include <string>

class fileLoader;

class NdForce
{
public:

	long loadCaseID, nodeID;
	double Fx, Fy, Fz;

	NdForce(void);
	~NdForce(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

