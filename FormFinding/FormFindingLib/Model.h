#pragma once

#include <iostream>
#include <string>
#include <map>
#include <Eigen\Dense>

#include "ModelItemsForwardDeclare.h"
#include "MapTypesDef.h"

class fileLoader;
class RigidGroup;

class Model
{
public:
	std::string modelNAME;

	std::map<long, FreedomCase*> freedomCases;
	// si usa UN SOLO freedom case!
	FreedomCase *selectedFreedomCase;

	std::map<long, Node*> nodes;
	std::map<long, Beam*> beams;
	std::map<long, Plate*> plates;

	std::map<long, group*> groups;
	std::map<long, LoadPattern*> loadPatterns;

	// le reazioni vincolari vanno associate a questo LoadPattern >> loadPattern_REAZ_V (LoadCase nel file di output)
	LoadPattern *loadPattern_REAZ_V;
	std::vector<NdForce* > REAZ_V;
	void generateNdForce_REAZ_V(std::map<Node*, Eigen::Vector3d>& mapREAZ_V);

	// force-density load pattern
	LoadPattern *loadPattern_FORCE_DENSITY;
	std::vector<BmPreLoad*> FORCE_DENSITY;
	void generateBmPreload_FORCE_DENSITY(std::map<Beam*, double>& mapFORCE_DENSITY);


	std::map<long, BeamProperty*> beamProperties;
	std::map<long, PlateProperty*> plateProperties;
	std::map<long, BmAngle*> bmAngles;
	std::map<long, CoordSys*> coordSys;
	std::map<long, Stage*> stages;
	std::map<long, PlAngle*> plAngles;
	
	std::map<longPair, PlPressure*> PlPressures;
	
	std::vector<Restraint*> restraints;
	std::vector<BmEndRelease*> bmEndReleasesT;
	std::vector<BmEndRelease*> bmEndReleasesR;
	std::vector<PlPatchType*> plPatchTypes;
	std::vector<NdMoment*> ndMoments;
	std::vector<NdForce*> ndForces;
	std::vector<PlShear*> plShears;

	std::vector<NdTemp*> ndTemps;
	std::vector<BmPreLoad*> bmPreLoads;
	std::vector<PlPreLoad*> plPreLoads;
	std::vector<PlGlobalLoad*> plGlobalLoads;

	//std::map<longPair, BmDistLoadL*> bmDistLoadLs;
	//std::map<bmDistLoadGkey, BmDistLoadG*> bmDistLoadGs;
	std::vector<BmDistLoadL*> bmDistLoadLs;
	std::vector<BmDistLoadG*> bmDistLoadGs;

	std::vector<LoadCaseCombination*> loadCaseCombinations;
	// pointer to the form-finding Combination
	LoadCaseCombination * ffc;


	std::vector<RigidGroup*> rigidGroups;

	//TODO aggiungere tutte le map per contenere i dati

	//COPIA PARAMETRI MODEL
	// mettiamo qui tutte le LINES da copiare "pari-pari"
	char **linesToCopy;
	// sectionFirstLine[i] è l'indice in linesToCopy delle prima linea da copiare uguale
	long *sectionFirstLine;
	// sectionLinesCount[i] è il numero di linee che compongono la sezione i-esima
	long *sectionLinesCount;
	long sectionsCount;


	void exportSectionToStream(int i, std::ostream& ofs);

	Model(void);
	~Model(void);

	void clearModel();

	void printModelSummary();
	//void printComments();
	void writeCommentsToFiles(std::string basePathOut);
};

