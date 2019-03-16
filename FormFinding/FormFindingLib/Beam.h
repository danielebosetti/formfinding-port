#pragma once

#include <iostream>
#include <string>

class fileLoader;
class BeamProperty;
class Node;

// "Beam"
class Beam
{
public:

	long ID, Gr2, IDGroup, beamPropertyID, node1, node2;

	int material_type;

	bool isRigidLink;
	bool isElastic;

	double L0;
	double LS;
	double coeffEA; // product of area and (elastic-)modulus
	double axialStiffness;

	// sum of axial tensions, sum(LP.P0 * LoadCase.alphaMultiplier under FFLCC)
	double initialAxialForce;

	// initial beam length (introduced after flattening)
	double initialLength;


	// versore da node1 a node2
	//Vector3d versor;

	// for optimization:: NODE pointers!
	Node *pNode1, *pNode2;
	// BEAM_PROPERTY pointer
	BeamProperty *pBeamProperty;

	Beam(void);
	Beam(const Beam&);
	~Beam(void);

	void readFromFileLoader(fileLoader& fL);

	std::string toString();
	void exportToStream(std::ostream& ofs);

	double getLength();
};

