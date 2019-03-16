#pragma once

#include <iostream>
#include <string>

class fileLoader;

// "Group"

class group
{
public:

	long ID, color;
	std::string name;

	group(void);
	~group(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

