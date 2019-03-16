#pragma once

#include <iostream>
#include <string>
#include <vector>

class fileLoader;

class CoordSys
{
public:
	long ID;
	std::string name, type;

	std::vector<char*> otherProperties;

	CoordSys(void);
	~CoordSys(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

