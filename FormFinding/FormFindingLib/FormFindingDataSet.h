#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <Eigen/Dense>

class fileLoader;
class Node;
class Beam;

class FormFindingDataSet
{
public:
	std::vector<Node*> NODE_TC_L;
	std::vector<Node*> NODE_RL;
	std::vector<Node*> NODE_I;

	std::vector<Node*> NODE_RESTRAINED;

	std::map<Node*, Eigen::Vector3d> REAZ_V;
	std::map<Beam*, double> FORCE_DENSITY;

	//	map<Node*, Vector3d> forzaPeso;
	std::vector<Eigen::Vector3d> forzaPeso;
	std::vector<Eigen::Vector3d> ndForces_FFC;

	// resulting force on a node, due to PlatePressure
	std::vector<Eigen::Vector3d> forcePressure;

	FormFindingDataSet(void);
	~FormFindingDataSet(void);
	void clearFormFindingDataSet(void);
};

