#pragma once
#include <iostream>
#include <string>

class fileLoader;

// "PlShear"
class PlShear
{
public:
	long loadCaseID, plateID;
	double Tx, Ty;

	PlShear(void);
	~PlShear(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};
