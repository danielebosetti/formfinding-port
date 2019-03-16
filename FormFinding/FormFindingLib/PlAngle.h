#pragma once

#include <iostream>
#include <string>

class fileLoader;

class PlAngle
{
public:
	long ID;
	double angle;

	PlAngle(void);
	~PlAngle(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

