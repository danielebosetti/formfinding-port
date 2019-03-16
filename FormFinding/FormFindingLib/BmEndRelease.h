#pragma once
//#include "stdafx.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

class fileLoader;

// "BmEndReleaseT", "BmEndReleaseR"
class BmEndRelease
{
public:
	char charType; //R or T

	long ID;
	long end;

	std::vector<std::string> components;
	std::map<std::string, double> partialFixities;

	BmEndRelease(void);
	~BmEndRelease(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

