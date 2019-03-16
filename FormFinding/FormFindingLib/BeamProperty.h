#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

class fileLoader;

class BeamProperty
{
public:

	std::string type;

	long ID, color;
	std::string name;
	std::string materialName;

	double density, area;
	double modulus;

	double stiffnessMax;
	double modulusMultiplier;

	int material_type;
	bool isRigidLink;
	bool isElastic;

	std::map<std::string, double> dMap;
	std::map<std::string, std::string> sMap;

	std::vector<char*> properties;

	BeamProperty(void);
	~BeamProperty(void);

	void readFromFileLoader(fileLoader& fL);
	std::string toString();

	void exportToStream(std::ostream& ofs);
};

