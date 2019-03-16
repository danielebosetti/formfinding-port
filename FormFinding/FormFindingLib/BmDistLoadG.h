#pragma once
//#include "stdafx.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

class fileLoader;

// "BmDistLoadG"
class BmDistLoadG
{
public:
	long loadCase, beam;
	std::string dir;
	long boh;
	double fx, fy, fz, par1, par2, par3;
	std::string proj;

	BmDistLoadG(void);
	~BmDistLoadG(void);

	void readFromFileReader(fileLoader& fL);	
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

