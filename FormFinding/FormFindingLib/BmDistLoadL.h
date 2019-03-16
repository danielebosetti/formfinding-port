#pragma once

#include <iostream>
#include <string>

class fileLoader;

// "BmDistLoadL"
class BmDistLoadL
{
public:
	long IDFreedomCase, node, coordSys, boh;
	double comp1, comp2, disp1, disp2, disp3, disp4;

	BmDistLoadL(void);
	~BmDistLoadL(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();
	void exportToStream(std::ostream& ofs);
};

