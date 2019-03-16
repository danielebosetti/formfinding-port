#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

class fileLoader;

class PlateProperty
{
public:

	std::string type, elastProperty;

	long ID, color;
	std::string name;
	std::string materialName;

	int material_type;

	double memThick;
	double density;

	double stiffnessMax;
	double modulusMultiplier;

	std::map <std::string, std::string> sMap;
	std::map <std::string, double> dMap;

	std::vector<char*> properties;

	PlateProperty(void);
	~PlateProperty(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);

};

