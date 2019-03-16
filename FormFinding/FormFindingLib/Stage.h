#pragma once

#include <iostream>
#include <string>
#include <vector>

class fileLoader;

class Stage
{
public:
	long ID;
	std::string name;
	std::string setM, setRC;

	std::vector<char*> properties;

	Stage(void);
	~Stage(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

