#pragma once
//#include "stdafx.h"

#include <iostream>
#include <string>

class fileLoader;

// "FreedomCase"
class FreedomCase
{
public:

	long ID, boh1, boh2;
	std::string name;

	FreedomCase(void);
	~FreedomCase(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

