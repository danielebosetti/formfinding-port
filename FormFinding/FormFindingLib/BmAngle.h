#pragma once
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

class fileLoader;

// "BmAngle"
class BmAngle
{
public:
	long ID;
	double angle;

	BmAngle(void);
	~BmAngle(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

