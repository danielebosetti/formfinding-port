#pragma once
#include "stdafx.h"

class RigidGroup
{
public:
	Eigen::Vector3d baricenter, baricenterSpeed, angularMomentum ;
	Eigen::Vector3d sumTorque, sumForces;

	std::vector<Beam*> beamList;
	std::vector<Node*> nodeList;
	std::map <Node*, Eigen::Vector3d> forceOnNode;

	void setDeltaT(double newDeltaT);
	double deltaT;

	void computeBaricenter();
	void computeSumTorque();
	void computeSumForces();

	void setForceOnNode(Node *n, Eigen::Vector3d& f);

	void updateBaricenterMotion();
	void updatePoints();

	RigidGroup(void);
	~RigidGroup(void);
};

