#pragma once

#include <iostream>
#include <string>

class fileLoader;

class NdMoment
{
public:
	long loadCaseID;
	long nodeID;
	double	Mx, My, Mz;

	NdMoment(void);
	~NdMoment(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

