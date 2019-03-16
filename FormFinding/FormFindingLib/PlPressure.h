#pragma once
#include <iostream>
#include <string>

class fileLoader;

// "PlPressure"

class PlPressure
{
public:

	long loadPatternID, plateID;
	double plPressureValue;

	PlPressure(void);
	~PlPressure(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

